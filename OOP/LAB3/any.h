#pragma once
#include<typeinfo>

class any
{
public:
    template<typename T>
    any(const T& t) : held_(new holder<T>(t)), initialized_(true) {}

    any() : held_(new holder<int>(0)), initialized_(false) {}

    ~any() { delete held_; }

    template<typename U>
    U cast() const
    {
        if (typeid(U) != held_->type_info()) {
            throw std::exception("bad_cast");
        }
        if (!is_initialized()) {
            throw std::exception("Объект не инициализирован");
        }

        return static_cast<holder<U>*>(held_)->t_;
    }

    bool is_initialized() const
    {
        return initialized_;
    }

private:
    struct base_holder
    {
        virtual ~base_holder() {}
        virtual const std::type_info& type_info() const = 0;
    };

    template<typename T>
    struct holder : base_holder
    {
        holder(const T& t) : t_(t) {}

        const std::type_info& type_info() const
        {
            return typeid(t_);
        }

        T t_;
    };

private:
    bool initialized_;
    base_holder* held_;
};
