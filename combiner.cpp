#include<iostream>
#include<tuple>

template<class temp>
class policy_access;


template<typename... Ts>
class Combiner: public Ts::template f<Combiner<Ts...>>...{
std::tuple<Ts...> data;
public:
Combiner(std::tuple<Ts...> d):data{std::move(d)}{}
friend class policy_access<Combiner>;
};
