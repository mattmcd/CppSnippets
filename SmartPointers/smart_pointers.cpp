#include <iostream>
#include <memory>
#include <string>

class PayOff {
  public:
    virtual double operator()(double spot) const =0;
};

class PayOffCall : public PayOff {
  public:
    PayOffCall( double strike_ ) : strike(strike_) {}
    virtual double operator()(double spot) const { 
      return spot > strike ? spot - strike : 0; }
  private:
    double strike;
};

// Define a couple of Option classes using different memory management
// strategies for the PayOff pointer.  Define a dummy () operator to test
// whether the PayOff pointer is being used correctly.

class OptionUnique {
  // Take ownership of payoff object
  public:
    OptionUnique( std::unique_ptr<PayOff> payOff_, double expiry_ ) : 
      expiry(expiry_), payOff( std::move(payOff_) ) {}
    double operator()(double spot) { return (*payOff)(spot);};
  private:
    double expiry;
    std::unique_ptr<PayOff> payOff;
};

class OptionShared {
  // Share ownership of payoff object
  public:
    OptionShared( std::shared_ptr<PayOff> payOff_, double expiry_ ) : 
      expiry(expiry_), payOff(payOff_) { }
    double operator()(double spot) { return (*payOff)(spot);};
  private:
    double expiry;
    std::shared_ptr<PayOff> payOff;
};

int main(int argc, char* argv[])
{
  double strike = 50.0;
  double expiry = 90;
  std::unique_ptr<PayOff> payOffUnique( new PayOffCall(strike) );
  std::shared_ptr<PayOff> payOffShared( new PayOffCall(strike) );

  double spot = 60;
  OptionUnique option1( std::move(payOffUnique), expiry );
  std::cout << option1(spot) << std::endl;

  // Can't reuse unique_ptr - seg faults at run time if we try
  // since payOffUnique now just contains NULL
  // OptionUnique option2( std::move(payOffUnique), expiry );
  auto option2 = std::move(option1); // Can move option
  std::cout << option2(spot) << std::endl;
  // Now option1 is invalid and seg faults if used.
  // std::cout << option1(spot) << std::endl;
  
  // Can reuse shared_ptr
  OptionShared option3( payOffShared, expiry );
  std::cout << option3(spot) << std::endl;
  
  OptionShared option4( payOffShared, expiry );
  std::cout << option4(spot) << std::endl;

  auto option5 = option4;
  std::cout << option5(spot) << std::endl;

  return 0;
}
