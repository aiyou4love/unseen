#include "../../Include.hpp"

namespace cc {
	
	
	void Value::runFormat(boost::format& nFormat, int8_t nIndex)
	{
		if ( ((size_t)nIndex) > mIndexs.size() ) {
			return;
		}
		int16_t index_ = mIndexs[nIndex - 1];
		int8_t type_ = index_ >> 10;
		index_ &= 0x3FF;
		if (1 == type_) {
			if (((size_t)index_) > mInt8s.size()) {
				return;
			}
			nFormat % (mInt8s[index_ - 1]);
		} else if (2 == type_) {
			if (((size_t)index_) > mInt16s.size()) {
				return;
			}
			nFormat % (mInt16s[index_ - 1]);
		} else if (3 == type_) {
			if (((size_t)index_) > mInt32s.size()) {
				return;
			}
			nFormat % (mInt32s[index_ - 1]);
		} else if (4 == type_) {
			if (((size_t)index_) > mInt64s.size()) {
				return;
			}
			nFormat % (mInt64s[index_ - 1]);
		} else if (5 == type_) {
			if (((size_t)index_) > mFloats.size()) {
				return;
			}
			nFormat % (mFloats[index_ - 1]);
		} else if (6 == type_) {
			if (((size_t)index_) > mDoubles.size()) {
				return;
			}
			nFormat % (mDoubles[index_ - 1]);
		} else if (7 == type_) {
			if (((size_t)index_) > mStrings.size()) {
				return;
			}
			nFormat % (mStrings[index_ - 1]);
		} else if (8 == type_) {
			if (((size_t)index_) > mBuffers.size()) {
				return;
			}
			LOGERROR("[%s]%d,%d", __METHOD__, type_, index_);
		} else {
		}
	}
	
	void Value::pushValue(MYSQL_BIND& nValue, enum_field_types nBufType)
	{
		nValue.buffer_type = nBufType;
		nValue.length = nullptr;
		nValue.is_null_value = 0;
		nValue.is_unsigned = 0;
	}
	
	bool Value::pushValue(MYSQL_BIND& nValue, int8_t nIndex)
	{
		if ( ((size_t)nIndex) > mIndexs.size() ) {
			return false;
		}
		int16_t index_ = mIndexs[nIndex - 1];
		int8_t type_ = index_ >> 10;
		index_ &= 0x3FF;
		if (1 == type_) {
			if (((size_t)index_) > mInt8s.size()) {
				return false;
			}
			this->pushValue(nValue, MYSQL_TYPE_TINY);
			nValue.buffer = (&(mInt8s[index_ - 1]));
			nValue.buffer_length = 1;
		} else if (2 == type_) {
			if (((size_t)index_) > mInt16s.size()) {
				return false;
			}
			this->pushValue(nValue, MYSQL_TYPE_SHORT);
			nValue.buffer = (&(mInt16s[index_ - 1]));
			nValue.buffer_length = 2;
		} else if (3 == type_) {
			if (((size_t)index_) > mInt32s.size()) {
				return false;
			}
			this->pushValue(nValue, MYSQL_TYPE_LONG);
			nValue.buffer = (&(mInt32s[index_ - 1]));
			nValue.buffer_length = 4;
		} else if (4 == type_) {
			if (((size_t)index_) > mInt64s.size()) {
				return false;
			}
			this->pushValue(nValue, MYSQL_TYPE_LONGLONG);
			nValue.buffer = (&(mInt64s[index_ - 1]));
			nValue.buffer_length = 8;
		} else if (5 == type_) {
			if (((size_t)index_) > mFloats.size()) {
				return false;
			}
			this->pushValue(nValue, MYSQL_TYPE_FLOAT);
			nValue.buffer = (&(mFloats[index_ - 1]));
			nValue.buffer_length = 4;
		} else if (6 == type_) {
			if (((size_t)index_) > mDoubles.size()) {
				return false;
			}
			this->pushValue(nValue, MYSQL_TYPE_DOUBLE);
			nValue.buffer = (&(mDoubles[index_ - 1]));
			nValue.buffer_length = 8;
		} else if (7 == type_) {
			if (((size_t)index_) > mStrings.size()) {
				return false;
			}
			this->pushValue(nValue, MYSQL_TYPE_STRING);
			string& value_ = mStrings[index_ - 1];
			nValue.buffer = (void *)(value_.c_str());
			nValue.buffer_length = (unsigned long)(value_.length());
		} else if (8 == type_) {
			if (((size_t)index_) > mBuffers.size()) {
				return false;
			}
			BufferPtr& buffer_ = mBuffers[index_ - 1];
			if (buffer_->getLength() < 1) {
				return false;
			}
			this->pushValue(nValue, MYSQL_TYPE_BLOB);
			nValue.buffer = buffer_->getValue();
			nValue.buffer_length = buffer_->getLength();
		} else {
			return false;
		}
		return true;
	}
	
	bool Value::getValue(int8_t& nValue, int8_t nIndex)
	{
		if ( ((size_t)nIndex) > mIndexs.size() ) {
			return false;
		}
		int16_t index_ = mIndexs[nIndex - 1];
		int8_t type_ = index_ >> 10;
		index_ &= 0x3FF;
		if (1 == type_) {
			if (((size_t)index_) > mInt8s.size()) {
				return false;
			}
			nValue = mInt8s[index_ - 1];
		} else if (2 == type_) {
			if (((size_t)index_) > mInt16s.size()) {
				return false;
			}
			nValue = (int8_t)(mInt16s[index_ - 1]);
		} else if (3 == type_) {
			if (((size_t)index_) > mInt32s.size()) {
				return false;
			}
			nValue = (int8_t)(mInt32s[index_ - 1]);
		} else if (4 == type_) {
			if (((size_t)index_) > mInt64s.size()) {
				return false;
			}
			nValue = (int8_t)(mInt64s[index_ - 1]);
		} else if (5 == type_) {
			if (((size_t)index_) > mFloats.size()) {
				return false;
			}
			nValue = (int8_t)(mFloats[index_ - 1]);
		} else if (6 == type_) {
			if (((size_t)index_) > mDoubles.size()) {
				return false;
			}
			nValue = (int8_t)(mDoubles[index_ - 1]);
		} else if (7 == type_) {
			if (((size_t)index_) > mStrings.size()) {
				return false;
			}
			string& value_ = mStrings[index_ - 1];
			nValue = (int8_t)(strToInt32(value_.c_str()));
		} else if (8 == type_) {
			if (((size_t)index_) > mBuffers.size()) {
				return false;
			}
			BufferPtr& buffer_ = mBuffers[index_ - 1];
			if (buffer_->getLength() < 1) {
				return false;
			}
			nValue = *((int8_t *)(buffer_->getValue()));
		} else {
			return false;
		}
		return true;
	}
	
	void Value::pushValue(int8_t nValue)
	{
		mInt8s.push_back(nValue);
		int16_t index_ = (1 << 10);
		index_ |= (int16_t)(mInt8s.size());
		mIndexs.push_back(index_);
	}
	
	bool Value::getValue(int16_t& nValue, int8_t nIndex)
	{
		if (((size_t)nIndex) > mIndexs.size()) {
			return false;
		}
		int16_t index_ = mIndexs[nIndex - 1];
		int8_t type_ = index_ >> 10;
		index_ &= 0x3FF;
		if (1 == type_) {
			if (((size_t)index_) > mInt8s.size()) {
				return false;
			}
			nValue = (int16_t)(mInt8s[index_ - 1]);
		} else if (2 == type_) {
			if (((size_t)index_) > mInt16s.size()) {
				return false;
			}
			nValue = mInt16s[index_ - 1];
		} else if (3 == type_) {
			if (((size_t)index_) > mInt32s.size()) {
				return false;
			}
			nValue = (int16_t)(mInt32s[index_ - 1]);
		} else if (4 == type_) {
			if (((size_t)index_) > mInt64s.size()) {
				return false;
			}
			nValue = (int16_t)(mInt64s[index_ - 1]);
		} else if (5 == type_) {
			if (((size_t)index_) > mFloats.size()) {
				return false;
			}
			nValue = (int16_t)(mFloats[index_ - 1]);
		} else if (6 == type_) {
			if (((size_t)index_) > mDoubles.size()) {
				return false;
			}
			nValue = (int16_t)(mDoubles[index_ - 1]);
		} else if (7 == type_) {
			if (((size_t)index_) > mStrings.size()) {
				return false;
			}
			string& value_ = mStrings[index_ - 1];
			nValue = (int16_t)(strToInt32(value_.c_str()));
		} else if (8 == type_) {
			if (((size_t)index_) > mBuffers.size()) {
				return false;
			}
			BufferPtr& buffer_ = mBuffers[index_ - 1];
			if (buffer_->getLength() < 2) {
				return false;
			}
			nValue = *((int16_t *)(buffer_->getValue()));
		} else {
			return false;
		}
		return true;
	}
	
	void Value::pushValue(int16_t nValue)
	{
		mInt16s.push_back(nValue);
		int16_t index_ = (2 << 10);
		index_ |= (int16_t)(mInt16s.size());
		mIndexs.push_back(index_);
	}
	
	bool Value::getValue(int32_t& nValue, int8_t nIndex)
	{
		if (((size_t)nIndex) > mIndexs.size()) {
			return false;
		}
		int16_t index_ = mIndexs[nIndex - 1];
		int8_t type_ = index_ >> 10;
		index_ &= 0x3FF;
		if (1 == type_) {
			if (((size_t)index_) > mInt8s.size()) {
				return false;
			}
			nValue = (int32_t)(mInt8s[index_ - 1]);
		} else if (2 == type_) {
			if (((size_t)index_) > mInt16s.size()) {
				return false;
			}
			nValue = (int32_t)(mInt16s[index_ - 1]);
		} else if (3 == type_) {
			if (((size_t)index_) > mInt32s.size()) {
				return false;
			}
			nValue = mInt32s[index_ - 1];
		} else if (4 == type_) {
			if (((size_t)index_) > mInt64s.size()) {
				return false;
			}
			nValue = (int32_t)(mInt64s[index_ - 1]);
		} else if (5 == type_) {
			if (((size_t)index_) > mFloats.size()) {
				return false;
			}
			nValue = (int32_t)(mFloats[index_ - 1]);
		} else if (6 == type_) {
			if (((size_t)index_) > mDoubles.size()) {
				return false;
			}
			nValue = (int32_t)(mDoubles[index_ - 1]);
		} else if (7 == type_) {
			if (((size_t)index_) > mStrings.size()) {
				return false;
			}
			string& value_ = mStrings[index_ - 1];
			nValue = strToInt32(value_.c_str());
		} else if (8 == type_) {
			if (((size_t)index_) > mBuffers.size()) {
				return false;
			}
			BufferPtr& buffer_ = mBuffers[index_ - 1];
			if (buffer_->getLength() < 4) {
				return false;
			}
			nValue = *((int32_t *)(buffer_->getValue()));
		} else {
			return false;
		}
		return true;
	}
	
	void Value::pushValue(int32_t nValue)
	{
		mInt32s.push_back(nValue);
		int16_t index_ = (3 << 10);
		index_ |= (int16_t)(mInt32s.size());
		mIndexs.push_back(index_);
	}
	
	bool Value::getValue(int64_t& nValue, int8_t nIndex)
	{
		if (((size_t)nIndex) > mIndexs.size()) {
			return false;
		}
		int16_t index_ = mIndexs[nIndex - 1];
		int8_t type_ = index_ >> 10;
		index_ &= 0x3FF;
		if (1 == type_) {
			if (((size_t)index_) > mInt8s.size()) {
				return false;
			}
			nValue = (int64_t)(mInt8s[index_ - 1]);
		} else if (2 == type_) {
			if (((size_t)index_) > mInt16s.size()) {
				return false;
			}
			nValue = (int64_t)(mInt16s[index_ - 1]);
		} else if (3 == type_) {
			if (((size_t)index_) > mInt32s.size()) {
				return false;
			}
			nValue = (int64_t)(mInt32s[index_ - 1]);
		} else if (4 == type_) {
			if (((size_t)index_) > mInt64s.size()) {
				return false;
			}
			nValue = mInt64s[index_ - 1];
		} else if (5 == type_) {
			if (((size_t)index_) > mFloats.size()) {
				return false;
			}
			nValue = (int64_t)(mFloats[index_ - 1]);
		} else if (6 == type_) {
			if (((size_t)index_) > mDoubles.size()) {
				return false;
			}
			nValue = (int64_t)(mDoubles[index_ - 1]);
		} else if (7 == type_) {
			if (((size_t)index_) > mStrings.size()) {
				return false;
			}
			string& value_ = mStrings[index_ - 1];
			nValue = strToInt64(value_.c_str());
		} else if (8 == type_) {
			if (((size_t)index_) > mBuffers.size()) {
				return false;
			}
			BufferPtr& buffer_ = mBuffers[index_ - 1];
			if (buffer_->getLength() < 8) {
				return false;
			}
			nValue = *((int64_t *)(buffer_->getValue()));
		} else {
			return false;
		}
		return true;
	}
	
	void Value::pushValue(int64_t nValue)
	{
		mInt64s.push_back(nValue);
		int16_t index_ = (4 << 10);
		index_ |= (int16_t)(mInt64s.size());
		mIndexs.push_back(index_);
	}
	
	bool Value::getValue(float& nValue, int8_t nIndex)
	{
		if ( ((size_t)nIndex) > mIndexs.size()) {
			return false;
		}
		int16_t index_ = mIndexs[nIndex - 1];
		int8_t type_ = index_ >> 10;
		index_ &= 0x3FF;
		if (1 == type_) {
			if (((size_t)index_) > mInt8s.size()) {
				return false;
			}
			nValue = (float)(mInt8s[index_ - 1]);
		} else if (2 == type_) {
			if (((size_t)index_) > mInt16s.size()) {
				return false;
			}
			nValue = (float)(mInt16s[index_ - 1]);
		} else if (3 == type_) {
			if (((size_t)index_) > mInt32s.size()) {
				return false;
			}
			nValue = (float)(mInt32s[index_ - 1]);
		} else if (4 == type_) {
			if (((size_t)index_) > mInt64s.size()) {
				return false;
			}
			nValue = (float)(mInt64s[index_ - 1]);
		} else if (5 == type_) {
			if (((size_t)index_) > mFloats.size()) {
				return false;
			}
			nValue = mFloats[index_ - 1];
		} else if (6 == type_) {
			if (((size_t)index_) > mDoubles.size()) {
				return false;
			}
			nValue = (float)(mDoubles[index_ - 1]);
		} else if (7 == type_) {
			if (((size_t)index_) > mStrings.size()) {
				return false;
			}
			string& value_ = mStrings[index_ - 1];
			nValue = (float)(strToDouble(value_.c_str()));
		} else if (8 == type_) {
			if (((size_t)index_) > mBuffers.size()) {
				return false;
			}
			BufferPtr& buffer_ = mBuffers[index_ - 1];
			if (buffer_->getLength() < 4) {
				return false;
			}
			nValue = *((float *)(buffer_->getValue()));
		} else {
			return false;
		}
		return true;
	}
	
	void Value::pushValue(float nValue)
	{
		mFloats.push_back(nValue);
		int16_t index_ = (5 << 10);
		index_ |= (int16_t)(mFloats.size());
		mIndexs.push_back(index_);
	}
	
	bool Value::getValue(double& nValue, int8_t nIndex)
	{
		if (((size_t)nIndex) > mIndexs.size()) {
			return false;
		}
		int16_t index_ = mIndexs[nIndex - 1];
		int8_t type_ = index_ >> 10;
		index_ &= 0x3FF;
		if (1 == type_) {
			if (((size_t)index_) > mInt8s.size()) {
				return false;
			}
			nValue = (double)(mInt8s[index_ - 1]);
		} else if (2 == type_) {
			if (((size_t)index_) > mInt16s.size()) {
				return false;
			}
			nValue = (double)(mInt16s[index_ - 1]);
		} else if (3 == type_) {
			if (((size_t)index_) > mInt32s.size()) {
				return false;
			}
			nValue = (double)(mInt32s[index_ - 1]);
		} else if (4 == type_) {
			if (((size_t)index_) > mInt64s.size()) {
				return false;
			}
			nValue = (double)(mInt64s[index_ - 1]);
		} else if (5 == type_) {
			if (((size_t)index_) > mFloats.size()) {
				return false;
			}
			nValue = (double)(mFloats[index_ - 1]);
		} else if (6 == type_) {
			if (((size_t)index_) > mDoubles.size()) {
				return false;
			}
			nValue = mDoubles[index_ - 1];
		} else if (7 == type_) {
			if (((size_t)index_) > mStrings.size()) {
				return false;
			}
			string& value_ = mStrings[index_ - 1];
			nValue = strToDouble(value_.c_str());
		} else if (8 == type_) {
			if (((size_t)index_) > mBuffers.size()) {
				return false;
			}
			BufferPtr& buffer_ = mBuffers[index_ - 1];
			if (buffer_->getLength() < 8) {
				return false;
			}
			nValue = *((double *)(buffer_->getValue()));
		} else {
			return false;
		}
		return true;
	}
	
	void Value::pushValue(double nValue)
	{
		mDoubles.push_back(nValue);
		int16_t index_ = (6 << 10);
		index_ |= (int16_t)(mDoubles.size());
		mIndexs.push_back(index_);
	}
	
	bool Value::getValue(string& nValue, int8_t nIndex)
	{
		if (((size_t)nIndex) > mIndexs.size()) {
			return false;
		}
		int16_t index_ = mIndexs[nIndex - 1];
		int8_t type_ = index_ >> 10;
		index_ &= 0x3FF;
		if (1 == type_) {
			if (((size_t)index_) > mInt8s.size()) {
				return false;
			}
			nValue = int32ToStr(mInt8s[index_ - 1]);
		} else if (2 == type_) {
			if (((size_t)index_) > mInt16s.size()) {
				return false;
			}
			nValue = int32ToStr(mInt16s[index_ - 1]);
		} else if (3 == type_) {
			if (((size_t)index_) > mInt32s.size()) {
				return false;
			}
			nValue = int32ToStr(mInt32s[index_ - 1]);
		} else if (4 == type_) {
			if (((size_t)index_) > mInt64s.size()) {
				return false;
			}
			nValue = int64ToStr(mInt64s[index_ - 1]);
		} else if (5 == type_) {
			if (((size_t)index_) > mFloats.size()) {
				return false;
			}
			nValue = doubleToStr(mFloats[index_ - 1]);
		} else if (6 == type_) {
			if (((size_t)index_) > mDoubles.size()) {
				return false;
			}
			nValue = doubleToStr(mDoubles[index_ - 1]);
		} else if (7 == type_) {
			if (((size_t)index_) > mStrings.size()) {
				return false;
			}
			nValue = mStrings[index_ - 1];
		} else if (8 == type_) {
			if (((size_t)index_) > mBuffers.size()) {
				return false;
			}
			BufferPtr& buffer_ = mBuffers[index_ - 1];
			nValue.assign(buffer_->getValue(), buffer_->getLength());
		} else {
			return false;
		}
		return true;
	}
	
	void Value::pushValue(string& nValue)
	{
		mStrings.push_back(nValue);
		int16_t index_ = (7 << 10);
		index_ |= (int16_t)(mStrings.size());
		mIndexs.push_back(index_);
	}
	
	bool Value::getValue(BufferPtr& nValue, int8_t nIndex)
	{
		if (((size_t)nIndex) > mIndexs.size()) {
			return false;
		}
		int16_t index_ = mIndexs[nIndex - 1];
		int8_t type_ = index_ >> 10;
		index_ &= 0x3FF;
		if (1 == type_) {
			if (((size_t)index_) > mInt8s.size()) {
				return false;
			}
			nValue.reset(new Buffer((char *)(&(mInt8s[index_ - 1])), 1));
		} else if (2 == type_) {
			if (((size_t)index_) > mInt16s.size()) {
				return false;
			}
			nValue.reset(new Buffer((char *)(&(mInt16s[index_ - 1])), 2));
		} else if (3 == type_) {
			if (((size_t)index_) > mInt32s.size()) {
				return false;
			}
			nValue.reset(new Buffer((char *)(&(mInt32s[index_ - 1])), 4));
		} else if (4 == type_) {
			if (((size_t)index_) > mInt64s.size()) {
				return false;
			}
			nValue.reset(new Buffer((char *)(&(mInt64s[index_ - 1])), 8));
		} else if (5 == type_) {
			if (((size_t)index_) > mFloats.size()) {
				return false;
			}
			nValue.reset(new Buffer((char *)(&(mFloats[index_ - 1])), 4));
		} else if (6 == type_) {
			if (((size_t)index_) > mDoubles.size()) {
				return false;
			}
			nValue.reset(new Buffer((char *)(&(mDoubles[index_ - 1])), 8));
		} else if (7 == type_) {
			if (((size_t)index_) > mStrings.size()) {
				return false;
			}
			string& value_ = mStrings[index_ - 1];
			nValue.reset(new Buffer((char *)(value_.c_str()), (int16_t)(value_.length())));
		} else if (8 == type_) {
			if (((size_t)index_) > mBuffers.size()) {
				return false;
			}
			nValue = mBuffers[index_ - 1];
		} else {
			return false;
		}
		return true;
	}
	
	void Value::pushValue(BufferPtr& nValue)
	{
		mBuffers.push_back(nValue);
		int16_t index_ = (8 << 10);
		index_ |= (int16_t)(mBuffers.size());
		mIndexs.push_back(index_);
	}
	
	Value::Value()
	{
		mIndexs.clear();
		mInt8s.clear();
		mInt16s.clear();
		mInt32s.clear();
		mInt64s.clear();
		mFloats.clear();
		mDoubles.clear();
		mStrings.clear();
		mBuffers.clear();
	}
	
	Value::~Value()
	{
		mIndexs.clear();
		mInt8s.clear();
		mInt16s.clear();
		mInt32s.clear();
		mInt64s.clear();
		mFloats.clear();
		mDoubles.clear();
		mStrings.clear();
		mBuffers.clear();
	}
	
}
