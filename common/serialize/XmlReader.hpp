#pragma once

namespace std {
	
	class XmlReader : noncopyable
	{
	public:
		template <typename T>
		void runNumber(T& nValue, const char * nName)
		{
			xml_attribute<char> * xmlAttribute_ = 
				mXmlNode->first_attribute(nName);
			if (nullptr == xmlAttribute_) {
				nValue = defaultValue<T>();
				return;
			}
			char * text_ = xmlAttribute_->value();
			nValue = __convert<const char *, T>(text_);
		}
		
		template <typename T>
		void runNumbers(T& nValue, const char * nName)
		{
			char * text_ = mXmlNode->value();
			nValue = __convert<const char *, T>(text_);
		}
		
		void runNumber(string& nValue, const char * nName);
		void runNumbers(string& nValue, const char * nName);
		
		void runTime(int64_t& nValue, const char * nName);
		void runTimes(int64_t& nValue, const char * nName);
		
		void runPush(const char * nName);
		bool runChild(const char * nName);
		bool runNext(const char * nName);
		void runPop(const char * nName);
		
		void pushClass(const char * nName);
		void popClass(const char * nName);
		
		void selectStream(const char * nValue);
		
		void loadFile(const char * nPath);
		
		void stringValue(const char * nValue);
		
		bool isText();
		
		XmlReader();
		~XmlReader();
		
	private:
		xml_document<char> mXmlDocument;
		xml_node<char> * mXmlNode;
		shared_ptr<file<char> > mFileDoc;
		stack<xml_node<char> *> mXmlNodes;
	};
	
}
