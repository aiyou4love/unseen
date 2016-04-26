#pragma once

namespace cc {
	
	class Instance : noncopyable
	{
	public:
		template <class T>
		static void instance(shared_ptr<T>& nValue)
		{
			nValue.reset(new T());
		}
		
		template <class T>
		static void instance(T *& nValue)
		{
			nValue = new T();
		}
	};
	
}
