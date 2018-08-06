

template<unsigned K,class R,class F,class Tup>
struct Expander{
  template<class... Us>
   static R expand(F f,Tup&& t,Us... args){
    return Expander<K-1,R,F,Tup>::
    expand(f,std::forward(t),get<K-1>(std::forward(t)),std::forward<Us>(args)...);
   }
};
