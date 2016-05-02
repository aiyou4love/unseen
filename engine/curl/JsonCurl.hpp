#pragma once

namespace cc {
	
	class JsonCurl : public StringCurl
	{
	public:
		template <class T>
		void runClass(T nClass, const char * nName)
		{
			JsonReader jsonReader_;
			jsonReader_.stringValue(mValue.c_str());
			IoReader<JsonReader> ioReader_(jsonReader_);
			ioReader_.selectStream(nName);
			nClass->headSerialize(ioReader_, nName);
		}
		
		JsonCurl();
		~JsonCurl();
	};
	
}
