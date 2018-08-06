#include <iostream>


template<typename... Ts>
class Combiner: public Ts::template f<Combiner<Ts>...>... {
	std::tuple<Ts...> data;
	public:
	Combiner(std::tuple<Ts...> d):data{std::move(d)}{}
	friend class policy_access<Combiner>;
};

/* Notes:

   According to what i understand uptil now. Combiner is a generic class template for combining various policies that a concrete class implementation might depend on. A variant of CRTP is beig used here. f is a nested alias type that every policy class implements. And for a given type of the Combiner class (Combiner<Ts>...) it returns the public interface of the respective policy class for this type. Policies are divided into two halves. One is the public interface and the other is the private data part. policy_access later. */

template<typename T>
struct policy_access{
  decltype(T::data)& data;
  template<typename U>
  policy_access(U* p):data{static_cast<T*>(p)->data}{}
  template<typename U>
  decltype(std::get<U>(data))& operator[](index_t<U>){
  return std::get<U>(data);
  }
};

/*policy_access is a way by which the public interface of a policy based class can access the private data. The second half of each policy class as mentioned earlier is a private interface and hence policy_access is helper class which allows each public interface to access its private data which is stored in std::tuple<Ts...> data. policy_access also has an [] operator which has been overloaded in order to acess the private data based on the type of the policy. */

struct my_policy;

/* This is the public interface of a policy*/
template<typename T>
struct my_public_policy{
void foo(){
  pbcd::policy_access<T>(this)[idx<my_policy>].i_++;
}

};

struct my_policy{
int i_;
template<typename T>
using f=my_public_policy<T>;
int meaning_of_life()
{
return 43;
}
};
