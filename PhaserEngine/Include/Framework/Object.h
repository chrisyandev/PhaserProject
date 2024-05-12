#pragma once

namespace ph
{
	class Object
	{
	public:
		Object();
		virtual ~Object();
		void destroy();
		bool isPendingDestroy() const { return m_bPendingDestroy; }

	private:
		bool m_bPendingDestroy;
	};
}