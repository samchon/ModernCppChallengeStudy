#pragma once
#include "MatrixIterator.hpp"

namespace ch2
{
	template <typename T>
	class Matrix
	{
	private:
		T *data_;
		size_t row_;
		size_t col_;

	public:
		typedef T value_type;
		typedef MatrixIterator<Matrix<T>> iterator;
		typedef const MatrixIterator<Matrix<T>> const_iterator;

	public:
		/* ---------------------------------------------------------------
			CONSTRUCTORS
		--------------------------------------------------------------- */
		Matrix(size_t row, size_t col)
		{
			this->row_ = row;
			this->col_ = col;

			this->data_ = new T[row * col];
		};

		Matrix(const Matrix &matrix)
		{
			this->row_ = matrix.row_;
			this->col_ = matrix.col_;

			memcpy(this->data_, matrix.data_, sizeof(T) * matrix.row_ * matrix.col_)
		};

		~Matrix()
		{
			delete[] this->data_;
		};

		/* ---------------------------------------------------------------
			ACCECSSORS
		--------------------------------------------------------------- */
		T** data() const { return this->data_; };
		size_t size() const { return this->row_ * this->col_; };

		size_t row() const { return this->row_; };
		size_t col() const { return this->col_; };

		T& at(size_t r, size_t c)
		{
			return *(data_ + r * this->col_ + c);
		};
		T&& at(size_t r, size_t c) const
		{
			return *(data_ + r * this->col_ + c);
		};

		iterator begin()
		{
			return iterator((Matrix<T>)this, 0, 0);
		};
		iterator end()
		{
			return iterator((Matrix<T>)this, row(), 0);
		};

		/* ---------------------------------------------------------------
			UTILITIES
		--------------------------------------------------------------- */
		template <typename U>
		void fill(U &&val)
		{
			for (size_t i = 0; i < size(); ++i)
				data_[i] = val;
		};

		void swap(Matrix &matrix)
		{
			std::swap(this->row_, matrix.row_);
			std::swap(this->col_, matrix.col);
			std::swap(this->data_, matrix.data_);
		};
	};
};