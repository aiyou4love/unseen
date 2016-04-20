#pragma once

namespace std {
	
	class ConfigEngine : noncopyable
	{
	public:
		template <class T>
		void runConfig(T nClass)
		{
			JsonReader jsonReader_;
			jsonReader_.loadFile(nClass->streamUrl());
			jsonReader_.selectStream(nClass->streamName());
			IoReader<JsonReader> ioReader(jsonReader_);
			nClass->headSerialize(ioReader);
		}
		
		static ConfigEngine& instance();
		
		ConfigEngine();
		~ConfigEngine();
		
	private:
		static ConfigEngine mConfigEngine;
	};
	
}
