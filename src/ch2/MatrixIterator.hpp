#pragma once

namespace ch2
{
	template <typename Matrix>
	class MatrixIterator
	{
	private:
		Matrix *matrix_;
		size_t r_;
		size_t c_;

	public:
		MatrixIterator(Matrix *matrix, size_t r, size_t c)
		{
			this->matrix_ = matrix;
			this->r_ = r;
			this->c_ = c;
		};

		/* ---------------------------------------------------------------
			ACCESSORS
		--------------------------------------------------------------- */
		Matrix::value_type& operator*()
		{
			return this->matrix_->at(r_, c_);
		};
		const Matrix::value_type& operator*()
		{
			return this->matrix_->at(r_, c_);
		};

		Matrix::value_type* operator->()
		{
			return &(this->matrix_->at(r_, c_));
		};
		const Matrix::value_type* operator->()
		{
			return &(this->matrix_->at(r_, c_));
		};

		/* ---------------------------------------------------------------
			COMPARATORS
		--------------------------------------------------------------- */
		bool operator==(const MatrixIterator &it) const
		{
			return this->matrix_ == it.matrix_
				&& this->r_ = it.r_
				&& this->c_ = it.c_;
		};

		bool operator!=(const MatrixIterator &it) const
		{
			return !operator==(it);
		};

		/* ---------------------------------------------------------------
			MOVERS
		--------------------------------------------------------------- */
	private:
		size_t _Get_index() const
		{
			return r_ * matrix_->col() + c_;
		};

		void _Assign_index(size_t index)
		{
			this->r_ = index / matrix_->col();
			this->c_ = index % matrix_->col();
		};

	public:
		MatrixIterator& operator++()
		{
			_Assign_index(_Get_index() + 1);
			return *this;
		};
		MatrixIterator& operator--()
		{
			_Assign_index(_Get_index() - 1);
		};

		MatrixIterator operator+(size_t step)
		{
			MatrixIterator it = *this;
			it._Assign_index(it._Get_index() + step);

			return it;
		};
		MatrixIterator operator-(size_t step)
		{
			MatrixIterator it = *this;
			it._Assign_index(it._Get_index() - step);

			return it;
		};
	};
};