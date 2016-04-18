#pragma once

namespace std {
	
	template <class __t>
	class IoWriter : noncopyable
	{
	public:
		template <typename __t0>
		void runNumber(__t0& nValue, const char * nName)
		{
			mArchive.runNumber(nValue, nName);
		}
		
		template <typename __t0, typename __t1>
		void runNumbers(__t0& nValue, const char * nNames, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					__t1& value_ = (*it);
					mArchive.runNumbers(value_, nName);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					__t1& value_ = (*it);
					mArchive.runNumber(value_, nName);
				}
			}
		}
		
		template <typename __t0>
		void runNumberCount(__t0& nValue, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				string name_ = nName; name_ += "_";
				name_.append(__convert<int32_t, string>(nCount));
				mArchive.runNumber(nValue, name_.c_str());
			} else {
				mArchive.runNumber(nValue, nName);
			}
		}
		
		template <typename __t0, typename __t1>
		void runNumbersCount(__t0& nValue, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				int8_t count_ = 0;
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					__t1 tempValue_ = (*it);
					this->runNumberCount(tempValue_, nName, count_);
					count_++;
				}
				__t1 value_ = defaultValue<__t1>();
				for (int8_t i = count_; i < nCount; ++i) {
					this->runNumberCount(value_, nName, i);
				}
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					__t1& value_ = (*it);
					mArchive.runNumber(value_, nName);
				}
			}
		}
		
		template <typename __t0, typename __t1>
		void runNumberSemi(__t0& nValue, const char * nName)
		{
			if ( mArchive.isText() ) {
				string value_ = stringCombine<__t0, __t1>(nValue, ":");
				mArchive.runNumber(value_, nName);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					__t1& value_ = (*it);
					mArchive.runNumber(value_, nName);
				}
			}
		}
		
		void runCrc32(int32_t& nValue, const char * nName)
		{
			if ( mArchive.isText() ) {
				LOGERROR("[%s]%s", __METHOD__, nName);
			} else {
				mArchive.runNumber(nValue, nName);
			}
		}
		
		template <typename __t0>
		void runCrc32s(__t0& nValue, const char * nNames, const char * nName)
		{
			if ( mArchive.isText() ) {
				LOGERROR("[%s]%s,%s", __METHOD__, nNames, nName);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					int32_t& value_ = (*it);
					mArchive.runNumber(value_, nName);
				}
			}
		}
		
		void runCrc32Count(int32_t& nValue, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				LOGERROR("[%s]%s,%d", __METHOD__, nName, nCount);
			} else {
				mArchive.runNumber(nValue, nName);
			}
		}
		
		template <typename __t0>
		void runCrc32sCount(__t0& nValue, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				LOGERROR("[%s]%s,%d", __METHOD__, nName, nCount);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					int32_t& value_ = (*it);
					mArchive.runNumber(value_, nName);
				}
			}
		}
		
		template <typename __t0>
		void runCrc32Semi(__t0& nValue, const char * nName)
		{
			if ( mArchive.isText() ) {
				LOGERROR("[%s]%s", __METHOD__, nName);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					int32_t& value_ = (*it);
					mArchive.runNumber(value_, nName);
				}
			}
		}
		
		void runTime(int64_t& nValue, const char * nName)
		{
			mArchive.runTime(nValue, nName);
		}
		
		template <typename __t0>
		void runTimes(__t0& nValue, const char * nNames, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					int64_t& value_ = (*it);
					mArchive.runTimes(value_, nName);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					int64_t& value_ = (*it);
					mArchive.runTime(value_, nName);
				}
			}
		}
		
		void runTimeCount(int64_t& nValue, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				string name_ = nName; name_ += "_";
				name_.append(__convert<int32_t, string>(nCount));
				mArchive.runTime(nValue, name_.c_str());
			} else {
				mArchive.runTime(nValue, nName);
			}
		}
		
		template <typename __t0>
		void runTimesCount(__t0& nValue, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				int8_t count_ = 0;
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					int64_t& tempValue_ = (*it);
					this->runTimeCount(tempValue_, nName, count_);
					count_++;
				}
				int64_t value_ = 0;
				for (int8_t i = count_; i < nCount; ++i) {
					this->runTimeCount(value_, nName, i);
				}
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					int64_t& value_ = (*it);
					mArchive.runTime(value_, nName);
				}
			}
		}
		
		template <typename __t0>
		void runTimeSemi(__t0& nValue, const char * nName)
		{
			if ( mArchive.isText() ) {
				LOGERROR("[%s]%s", __METHOD__, nName);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					int64_t& value_ = (*it);
					mArchive.runTime(value_, nName);
				}
			}
		}
		
		template<typename __t0>
		void runStream(__t0& nValue, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nName);
				nValue.serialize(this, 0);
				mArchive.runPop(nName);
			} else {
				nValue.serialize(this, 0);
			}
		}
		
		template<typename __t0>
		void runStreamPtr(__t0& nValue, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nName);
				nValue->serialize(this, 0);
				mArchive.runPop(nName);
			} else {
				nValue->serialize(this, 0);
			}
		}
		
		template<typename __t0, typename __t1>
		void runStreams(__t0& nValue, const char * nNames, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					__t1& value_ = (*it);
					this->runStream(value_, nName);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					__t1& value_ = (*it);
					value_.serialize(this, 0);
				}
			}
		}
		
		template<typename __t0, typename __t1>
		void runStreamPtrs(__t0& nValue, const char * nNames, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					__t1& value_ = (*it);
					this->runStreamPtr(value_, nName);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					__t1& value_ = (*it);
					value_->serialize(this, 0);
				}
			}
		}
		
		template<typename __t0, typename __t1>
		void runMapStreams(map<__t0, __t1>& nValue, const char * nNames, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					__t1& value_ = it->second;
					this->runStream(value_, nName);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					__t1& value_ = it->second;
					value_.serialize(this, 0);
				}
			}
		}
		
		template<typename __t0, typename __t1>
		void runMapStreamPtrs(map<__t0, __t1>& nValue, const char * nNames, const char * nName)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					__t1& value_ = it->second;
					this->runStreamPtr(value_, nName);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					__t1& value_ = it->second;
					value_->serialize(this, 0);
				}
			}
		}
		
		template<typename __t0>
		void runStreamCount(__t0& nValue, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				string name_ = nName; name_ += "_";
				name_.append(__convert<int32_t, string>(nCount));
				mArchive.runPush(name_.c_str());
				nValue.serialize(this, nCount);
				mArchive.runPop(name_.c_str());
			} else {
				nValue.serialize(this, 0);
			}
		}
		
		template<typename __t0>
		void runStreamPtrCount(__t0& nValue, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				string name_ = nName; name_ += "_";
				name_.append(__convert<int32_t, string>(nCount));
				mArchive.runPush(name_.c_str());
				nValue->serialize(this, nCount);
				mArchive.runPop(name_.c_str());
			} else {
				nValue->serialize(this, 0);
			}
		}
		
		template<typename __t0, typename __t1>
		void runStreamsCount(__t0& nValue, const char * nNames, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				int8_t count_ = 0;
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					__t1& value_ = (*it);
					this->runStreamCount(value_, nName, count_);
					count_++;
				}
				 __t1 value_;
				for (int8_t i = count_; i < nCount; ++i) {
					this->runStreamCount(value_, nName, i);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					__t1& value_ = (*it);
					value_.serialize(this, 0);
				}
			}
		}
		
		template<typename __t0, typename __t1>
		void runStreamPtrsCount(__t0& nValue, const char * nNames, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				int8_t count_ = 0;
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					__t0& value_ = (*it);
					this->runStreamPtrCount(value_ nName, count_);
					count_++;
				}
				__t1 value_ = nullptr;
				Instance::instance(value_);
				for (int8_t i = count_; i < nCount; ++i) {
					this->runStreamPtrCount(value_, nName, i);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					__t1& value_ = (*it);
					value_->serialize(this, 0);
				}
			}
		}
		
		template<typename __t0, typename __t1>
		void runMapStreamsCount(map<__t0, __t1>& nValue, const char * nNames, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				int8_t count_ = 0;
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					__t1& value_ = it->second;
					this->runStreamCount(value_, nName, count_);
					count_++;
				}
				 __t1 value_;
				for (int8_t i = count_; i < nCount; ++i) {
					this->runStreamCount(value_, nName, i);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					__t1& value_ = it->second;
					value_.serialize(this, 0);
				}
			}
		}
		
		template<typename __t0, typename __t1>
		void runMapStreamPtrsCount(map<__t0, __t1>& nValue, const char * nNames, const char * nName, int8_t nCount)
		{
			if ( mArchive.isText() ) {
				mArchive.runPush(nNames);
				int8_t count_ = 0;
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					__t1& value_ = it->second;
					this->runStreamPtrCount(value_, nName, count_);
					count_++;
				}
				__t1 value_ = nullptr;
				Instance::instance(value_);
				for (int8_t i = count_; i < nCount; ++i) {
					this->runStreamPtrCount(value_, nName, i);
				}
				mArchive.runPop(nNames);
			} else {
				int16_t count_ = (int16_t)(nValue.size());
				mArchive.runNumber(count_, nName);
				auto it = nValue.begin();
				for ( ; it != nValue.end(); ++it ) {
					__t1& value_ = it->second;
					value_->serialize(this, 0);
				}
			}
		}
		
		template<typename __t>
		void selectStream(__t& nStream)
		{
			mArchive.selectStream(nStream->streamName());
		}
		
		IoWriter(__t& nArchive)			: mArchive(nArchive)
		{
		}
		
		~IoWriter()
		{
		}
		
	private:
		__t mArchive;
	};
	
}
