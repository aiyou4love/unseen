#include "../../Include.hpp"

namespace std {
	
	void XmlWriter::runNumber(string& nValue, const char * nName)
	{
		xml_attribute<char> * xmlAttribute_ =
			mXmlDocument.allocate_attribute(nName, nValue.c_str());
		mXmlNode->append_attribute(xmlAttribute_);
	}
	
	void XmlWriter::runNumbers(string& nValue, const char * nName)
	{
		xml_node<char> * xmlNode_ =
			mXmlDocument.allocate_node(node_element, nName, nValue.c_str());
		mXmlNode->append_node(xmlNode_);
	}
	
	void XmlWriter::runTime(int64_t& nValue, const char * nName)
	{
		LocalTime localTime_(nValue);
		string value_ = localTime_.stringTime();
		this->runNumber(value_, nName);
	}
		
	void XmlWriter::runTimes(int64_t& nValue, const char * nName)
	{
		LocalTime localTime_(nValue);
		string value_ = localTime_.stringTime();
		this->runNumbers(value_, nName);
	}
	
	void XmlWriter::runPush(const char * nName)
	{
		xml_node<char> * xmlNode_ =
			mXmlDocument.allocate_node(node_element, nName, nullptr);
		mXmlNode->append_node(xmlNode_);
		mXmlNode = xmlNode_;
	}
	
	void XmlWriter::runPop(const char * nName)
	{
		mXmlNode = mXmlNode->parent();
	}
	
	void XmlWriter::selectStream(const char * nValue)
	{
		xml_node<char> * xmlNode_ =
			mXmlDocument.allocate_node(node_element, nName, nullptr);
		mXmlDocument->append_node(xmlNode_);
		mXmlNode = xmlNode_;
	}
	
	void XmlWriter::saveFile(const char * nPath)
	{
		ofstream fstream_(nPath);
		fstream_ << mXmlDocument;
	}
	
	string XmlWriter::stringValue()
	{
		string result_;  
		rapidxml::print(back_inserter(result_), mXmlDocument, 0);
		return result_;
	}
	
	bool XmlWriter::isText()
	{
		return true;
	}
	
	XmlWriter::XmlWriter()
		: mXmlNode (nullptr)
	{
		#define XMLHEAD "xml version='1.0' encoding='utf-8'"
		char * xmlHeader_ = mXmlDocument.allocate_string(XMLHEAD);
		xml_node<char> * xmlNode_ = mXmlDocument.allocate_node(node_pi, xmlHeader_);
		mXmlDocument.append_node(xmlNode_);
	}
	
	XmlWriter::~XmlWriter()
	{
		mXmlNode = nullptr;
	}
	
}
