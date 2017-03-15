/* Вам нужно определить операторы +=, -=, *=, /= для класса Rational так, чтобы они могли принимать 
в качестве аргументов и объекты типа Rational и целые числа. Кроме того вам необходимо определить 
операторы унарного минуса и плюса для класса Rational. */

struct Rational
{
    	Rational(int numerator = 0, int denominator = 1);
	
    	Rational& operator+=(Rational const &r) {
		numerator_ = (numerator_ * r.denominator_) + (r.numerator_ * denominator_);
		denominator_ = denominator_ * r.denominator_;
		return *this;
	}
	
	Rational& operator-=(Rational const &r) {
		numerator_ = (numerator_ * r.denominator_) - (r.numerator_ * denominator_);
		denominator_ = denominator_ * r.denominator_;
		return *this;
	}
	
	Rational& operator*=(Rational const &r) {
		numerator_ *= r.numerator_;
		denominator_ *= r.denominator_;
		return *this;
	}
	
	Rational& operator/=(Rational const &r) {
		numerator_ *= r.denominator_;
		denominator_ *= r.numerator_;
		return *this;
	}
	
	Rational operator-() const {
		Rational temp;
		temp.numerator_ = -numerator_;
        temp.denominator_ = denominator_;
		return temp;
	}
	 
	Rational operator+() const {
        Rational temp;
        temp.numerator_ = numerator_;
        temp.denominator_ = denominator_;
		return temp;
	}

private:
    int numerator_;
    int denominator_;
};
