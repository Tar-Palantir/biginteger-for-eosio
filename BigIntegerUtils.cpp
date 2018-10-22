/** 
 * This source adapted from https://mattmccutchen.net/bigint/ by Mithrilcoin.io for EOS.IO smart contract.
 */
#include "BigIntegerUtils.hpp"
#include "BigUnsignedInABase.hpp"

string bigUnsignedToString( const BigUnsigned &x) {
	return string(BigUnsignedInABase(x, BigUnsignedInABase::Base(10) ) );
}

string bigIntegerToString( const  BigInteger &x) {
	return (x.getSign() == BigInteger::negative)
		? (string("-") + bigUnsignedToString(x.getMagnitude()))
		: (bigUnsignedToString(x.getMagnitude()));
}

BigUnsigned stringToBigUnsigned(const string &s) {
	return BigUnsigned(BigUnsignedInABase(s, BigUnsignedInABase::Base(10) ) );
}

BigInteger stringToBigInteger( const string &s) {
	// Recognize a sign followed by a BigUnsigned.
	const char signChar = s.c_str()[0];
	string childStr( s );
	
	return (signChar == '-') ? BigInteger(stringToBigUnsigned(childStr.substr(1, s.length() - 2)), BigInteger::negative)
		: (signChar == '+') ? BigInteger(stringToBigUnsigned(childStr.substr(1, s.length() - 2)))
		: BigInteger(stringToBigUnsigned(s));
}

// commented by swapnibble
/*
eosio::ostream &operator <<(eosio::ostream &os, const BigUnsigned &x) {
	BigUnsignedInABase::Base base;
	long osFlags = os.flags();
	if (osFlags & os.dec)
		base = 10;
	else if (osFlags & os.hex) {
		base = 16;
		if (osFlags & os.showbase)
			os << "0x";
	} else if (osFlags & os.oct) {
		base = 8;
		if (osFlags & os.showbase)
			os << '0';
	} else {
		throw "eosio::ostream << BigUnsigned: Could not determine the desired base from output-stream flags";
	}
	string s = string(BigUnsignedInABase(x, base));
	os << s;
	return os;
}

eosio::ostream &operator <<(eosio::ostream &os, const BigInteger &x) {
	if (x.getSign() == BigInteger::negative)
		os << '-';
	os << x.getMagnitude();
	return os;
}
*/