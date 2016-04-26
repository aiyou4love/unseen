#pragma once

namespace cc {
	
	class ConfigEngine : noncopyable
	{
	public:
		template <class T>
		void runConfig(T nClass)
		{
			string path_ = mAsset + nClass->streamUrl();
			JsonReader jsonReader_;
			jsonReader_.loadFile(path_.c_str());
			jsonReader_.selectStream(nClass->streamName());
			IoReader<JsonReader> ioReader(jsonReader_);
			nClass->headSerialize(ioReader);
		}
		
		static ConfigEngine& instance();
		
		ConfigEngine();
		~ConfigEngine();
		
	private:
		string mAsset;
		
		static ConfigEngine mConfigEngine;
	};
	
}
