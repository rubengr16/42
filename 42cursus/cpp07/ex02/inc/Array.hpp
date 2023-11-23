/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:34:28 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/23 19:14:56 by rgallego         ###   ########.fr       */
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

		explicit Array(unsigned int size):
			_array(new T[size]),
			_size(size)
		{
			std::cout << "[Constructor]: Array<>: has been created with size "
				<< this->_size << std::endl;
		}

		Array(const Array<T>& array):
			_array(new T[array.size()]),
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
			delete [] this->_array;
		}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Array<T>&	operator=(const Array<T>& array)
		{
			unsigned int	i;

			if (this == &array)
				return (*this);
			delete [] this->_array;
			this->_size = array.size();
			this->_array = new T[this->_size];
			for (i = 0; i < this->_size; i++)
				this->_array[i] = array[i];
			std::cout << "[Copy Assignment Operator]: Array<>: has been created with "
				<< "size " << this->_size << std::endl;
			return (*this);
		}

/* **************************** MEMBER FUNCTIONS **************************** */
		unsigned int	size(void) const
		{
			return (this->_size);
		}

		T&	operator[](unsigned int i) const
		{
			if (i >= this->_size)
				throw (IndexOutOfBoundsException());
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
