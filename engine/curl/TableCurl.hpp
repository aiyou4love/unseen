#pragma once

namespace cc {
	
	class TableCurl : public StringCurl
	{
	public:
		template <class T>
		void runClass(T nClass, const char * nName)
		{
			TableReader tableReader_;
			tableReader_.stringValue(mValue.c_str());
			IoReader<TableReader> ioReader_(tableReader_);
			ioReader_.selectStream(nName);
			nClass->headSerialize(ioReader_, nName);
		}
		
		TableCurl();
		~TableCurl();
	};
	
}
