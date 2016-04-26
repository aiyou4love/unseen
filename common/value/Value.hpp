#pragma once

namespace cc {
	
	class Value : noncopyable
	{
	public:
		template<class __t>
		void serialize(__t * nSerialize, int32_t nCount)
		{
			nSerialize->runNumbers<vector<int16_t>, int16_t>(mIndexs, "indexs", "index");
			nSerialize->runNumbers<vector<int8_t>, int8_t>(mInt8s, "int8s", "int8");
			nSerialize->runNumbers<vector<int16_t>, int16_t>(mInt16s, "int16s", "int16");
			nSerialize->runNumbers<vector<int32_t>, int32_t>(mInt32s, "int32s", "int32");
			nSerialize->runNumbers<vector<int64_t>, int64_t>(mInt64s, "int64s", "int64");
			nSerialize->runNumbers<vector<float>, float>(mFloats, "floats", "float");
			nSerialize->runNumbers<vector<double>, double>(mDoubles, "doubles", "double");
			nSerialize->runNumbers<vector<string>, string>(mStrings, "strings", "string");
			nSerialize->runStreamPtrs<vector<BufferPtr>, BufferPtr>(mBuffers, "buffers", "buffer");
		}
		void runFormat(boost::format& nFormat, int8_t nIndex);
		void pushValue(MYSQL_BIND& nValue, enum_field_types nBufType);
		bool pushValue(MYSQL_BIND& nValue, int8_t nIndex);
		bool getValue(int8_t& nValue, int8_t nIndex);
		void pushValue(int8_t nValue);
		bool getValue(int16_t& nValue, int8_t nIndex);
		void pushValue(int16_t nValue);
		bool getValue(int32_t& nValue, int8_t nIndex);
		void pushValue(int32_t nValue);
		bool getValue(int64_t& nValue, int8_t nIndex);
		void pushValue(int64_t nValue);
		bool getValue(float& nValue, int8_t nIndex);
		void pushValue(float nValue);
		bool getValue(double& nValue, int8_t nIndex);
		void pushValue(double nValue);
		bool getValue(string& nValue, int8_t nIndex);
		void pushValue(string& nValue);
		bool getValue(BufferPtr& nValue, int8_t nIndex);
		void pushValue(BufferPtr& nValue);
		
		Value();
		~Value();
		
	private:
		vector<int16_t> mIndexs;
		vector<int8_t> mInt8s;
		vector<int16_t> mInt16s;
		vector<int32_t> mInt32s;
		vector<int64_t> mInt64s;
		vector<float> mFloats;
		vector<double> mDoubles;
		vector<string> mStrings;
		vector<BufferPtr> mBuffers;
	};
	typedef shared_ptr<Value> ValuePtr;
	
}
