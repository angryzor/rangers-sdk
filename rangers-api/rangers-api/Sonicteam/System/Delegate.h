#pragma once

namespace csl::fnd {
    template<typename R>
    class Delegate;

    template<typename R, typename... A>
    class Delegate<R (A...)> {
        class DelegateFunctorBase {
            virtual ~DelegateFunctorBase() = default;
            virtual R operator()(A... args) = 0;
            virtual DelegateFunctorBase Clone() const = 0;
            virtual DelegateFunctorBase Move() = 0;
            virtual void* GetRuntimeTypeInfo() const = 0;
        };

        struct alignas(16) DelegateItem {
            char data[0x30];
            DelegateFunctorBase* functor;
        };

        template<typename F>
        class DelegateFunctor : public DelegateFunctorBase {
        public:
            F& func;

            DelegateFunctor(F& func) : func(func) {}

            virtual R operator()(A... args) {
                return this->func(args...);
            }

            virtual DelegateFunctor<F> Clone() const override { return *this; }
            virtual DelegateFunctor<F> Move() override { return std::move(*this); }
            virtual void* GetRuntimeTypeInfo() const { return nullptr; }
        };

        template<typename U>
        class DelegateFunctor<csl::ut::Pair<U*, R (U::*)(A...)>> : public DelegateFunctorBase {
        public:
            csl::ut::Pair<U*, R (U::*)(A...)> pair;

            DelegateFunctor(csl::ut::Pair<U*, R (U::*)(A...)> pair) : pair(pair) {}
            
            virtual R operator()(A... args) {
                return (this->pair.first->*this->pair.second)(args...);
            }

            virtual DelegateFunctor<csl::ut::Pair<U*, R (U::*)(A...)>> Clone() const override { return *this; }
            virtual DelegateFunctor<csl::ut::Pair<U*, R (U::*)(A...)>> Move() override { return std::move(*this); }
            virtual void* GetRuntimeTypeInfo() const { return nullptr; }
        };
        
    public:
        csl::ut::MoveArray<DelegateItem> functors;
        
        template<typename T> void Add(T& t) {
            DelegateItem item;
            DelegateFunctor<T> d(t);
            DelegateFunctor<T> *itemFunctor = &item.data;
            itemFunctor = d;
            item.functor = itemFunctor;
        }

        template<typename U> inline void Add(csl::ut::Pair<U*, R (U::*)(A...)> pair) {
            Add<csl::ut::Pair<U*, R (U::*)(A...)>>(pair);
        }
    };
}
