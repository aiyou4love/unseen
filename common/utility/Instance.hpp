#pragma once

namespace std {
	
	class Instance : noncopyable
	{
	public:
		template <class __t>
		static void instance(shared_ptr<__t>& nValue)
		{
			nValue.reset(new __t());
		}
		
		template <class __t>
		static void instance(__t *& nValue)
		{
			nValue = new __t();
		}
	};

}
