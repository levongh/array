#pragma once
#include <iterator>
#include <algorithm>

namespace eda {

template <typename T, size_t arr_size>
class array
{
    using value_type = T;
    using reference_type = value_type&;
    using iterator = value_type*;
    using const_iterator = const value_type*;
    using size_type = size_t;
    using difference_type = std::ptrdiff_t;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    /// @brief basic functionality
    /// @{
public:
    size_type size() const
    {
        return arr_size;
    }
    bool empty() const
    {
        return size() == 0;
    }

    /// @brief operator[]
    reference_type operator[](size_type idx)
    {
        return m_data[idx];
    }
    const reference_type operator[](size_type idx) const
    {
        return m_data[idx];
    }

    /// @brief at()
    reference_type at(size_type idx)
    {
        if (idx > arr_size) {
            throw std::out_of_range();
        }
        return m_data[arr_size];
    }
    const reference_type at(size_type idx) const
    {
        if (idx > arr_size) {
            throw std::out_of_range();
        }
        return m_data[arr_size];
    }

    /// @brief const and non const front
    reference_type front()
    {
        return *begin();
    }
    const reference_type front() const
    {
        return *begin();
    }

    /// @brief const and non const back
    reference_type back()
    {
        return arr_size ? *(end() - 1) : *end();
    }
    const reference_type back() const
    {
        return arr_size ? *(end() - 1) : *end();
    }

    reference_type data()
    {
        return &m_data[0];
    }
    const reference_type data() const
    {
        return &m_data[0];
    }

    void fill(const reference_type value)
    {
        std::fill(begin(), size(), value);
    }

    void swap(array& other)
    {
        std::swap(*this, other);
    }
    /// @}


    /// @brief iterator interfaces
    /// @{
public:
    /// @brief const and non const begin
    iterator begin()
    {
        return iterator(&m_data[0]);
    }
    const_iterator begin() const
    {
        return iterator(&m_data[0]);
    }

    /// @brief const and non const end
    iterator end()
    {
        return iterator(&m_data[arr_size]);
    }
    const_iterator end() const
    {
        return const_iterator(&m_data[arr_size]);
    }

    /// @brief const and non const  rbegin
   reverse_iterator rbegin()
   {
       return reverse_iterator(end());
   }
   const_reverse_iterator rbegin() const
   {
       return const_reverse_iterator(end());
   }

    /// @brief const and non const  rend
   reverse_iterator rend()
   {
       return reverse_iterator(begin());
   }
   const_reverse_iterator rend() const
   {
       return const_reverse_iterator(begin());
   }

   /// @brief cbegin/cend
   const_iterator cbegin() const
   {
       return const_iterator(&m_data[0]);
   }
   const_iterator cend() const
   {
       return const_iterator(&m_data[arr_size]);
   }

   /// @brief crbegin/crend
   const_iterator crbegin() const
   {
       return const_reverse_iterator(end());
   }
   const_iterator crend() const
   {
       return const_reverse_iterator(begin());
   }
    /// @}

private:
    value_type m_data[arr_size];
};

} //namespace eda
