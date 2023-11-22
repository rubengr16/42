/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:34:28 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/22 17:50:23 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		T*				_array;
		unsigned int	_size;

	public:
/* ****************************** CONSTRUCTORS ****************************** */
		Array(void):
			_array(),
			_size(0)
		{
			std::cout << "[Default Constructor]: Array<>: has been created "
				<< "with size " << this->_size << std::endl;
		}

		Array(unsigned int size):
			_array(new T[size]()),
			_size(size)
		{
			std::cout << "[Constructor]: Array<>: has been created with size "
				<< this->_size << std::endl;
		}

		Array(const Array<T>& array):
			_array(new T[array.size()]()),
			_size(array.size())
		{
			unsigned int	i;

			for (i = 0; i < this->_size; i++)
				this->_array[i] = array[i];
			std::cout << "[Copy Constructor]: Array<>: has been created with "
				<< "size " << this->_size << std::endl;
		}

/* ******************************* DESTRUCTOR ******************************* */
		~Array(void)
		{
			std::cout << "[Destructor]: Array<>: with size " << this->_size
				<< " is being destroyed" << std::endl;
			if (this->_array)
				delete this->_array;
		}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Array<T>&	operator=(const Array<T>& array)
		{
			unsigned int	i;

			if (this->_array)
				delete this->_array;
			this->_array = new T[array.size()];
			this->_size = array.size();
			for (i = 0; i < this->_size; i++)
				this->_array[i] = array[i];
			std::cout << "[Copy Constructor]: Array<>: has been created with "
				<< "size " << this->_size << std::endl;
		}

/* **************************** MEMBER FUNCTIONS **************************** */
		int	size(void)
		{
			return (this->_size);
		}

		T&	operator[](int i) const
		{
			if (i < 0 || i > this->size)
				throw IndexOutOfBoundsException();
			return (this->_array[i]);
		}
/* ******************************* EXCEPTIONS ******************************* */
	class IndexOutOfBoundsException: public std::exception
	{
		public:
			virtual const char*	what(void) const throw()
			{
				return ("[What] Array<>: Error! Index Out of Bounds");
			}
	};
};

#endif
