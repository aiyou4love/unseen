#pragma once

namespace cc {
	
	class ConfigEngine : noncopyable
	{
	public:
		template <class T>
		void runConfig(T nClass, const char * nUrl, const char * nName)
		{
			string path_ = mAsset + nUrl;
			JsonReader jsonReader_;
			jsonReader_.loadFile(path_.c_str());
			IoReader<JsonReader> ioReader_(jsonReader_);
			ioReader_.selectStream(nName);
			nClass->headSerialize(ioReader_, nName);
		}
		
		static ConfigEngine& instance();
		
		ConfigEngine();
		~ConfigEngine();
		
	private:
		string mAsset;
		
		static ConfigEngine mConfigEngine;
	};
	
}
