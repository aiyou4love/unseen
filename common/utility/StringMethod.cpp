#include "../../Include.hpp"

namespace std {
	
	string stringTrim(const string& nValue, const string& nTrim)
	{
		string value_("");
		for (size_t i = 0; i < nValue.length(); ++i) {
			if ((nValue[i] == ' ') || (nValue[i] == '\t')
				|| (nValue[i] == '\r') || (nValue[i] == '\n')) {
				continue;
			}
			bool find_ = false;
			for (size_t j = 0; j < nTrim.length(); ++j) {
				if ( nValue[i] == nTrim[j] ) {
					find_ = true;
					break;
				}
			}
			if (find_) continue;
			value_ = nValue.substr(i);
			break;
		}
		for (size_t i = value_.length(); i > 0; --i) {
			if ((value_[i - 1] == ' ') || (value_[i - 1] == '\t')
				|| (value_[i - 1] == '\r') || (value_[i - 1] == '\n')) {
				continue;
			}
			bool find_ = false;
			for (size_t j = 0; j < nTrim.length(); ++j) {
				if ( value_[i - 1] == nTrim[j] ) {
					find_ = true;
					break;
				}
			}
			if (find_) continue;
			value_ = value_.substr(0, i);
			break;
		}
		return value_;
	}
	
	string stringBackslant(const string& nValue)
	{
		string result_ = stringTrim(nValue, "/\\");
		for (size_t i = 0; i < result_.length(); ++i) {
			if ((result_[i] == '\\') ) {
				result_[i] = '/';
			}
		}
		return result_;
	}
	
}
