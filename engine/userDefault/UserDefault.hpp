#pragma once

namespace cc {
	
	class UserDefault : noncopyable
	{
	public:
		static UserDefault& instance();
		
		UserDefault();
		~UserDefault();
		
	private:
		list<
		string mAsset;
		
		static UserDefault mUserDefault;
	};
	
}
