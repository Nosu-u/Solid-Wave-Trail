#include <Geode.hpp>

using namespace cocos2d;

class $modify(HardStreak) {
	  void updateStroke(float b) { // modify the wave trail when it updates (always)
		m_isSolid = true; // makes it be a one color
		HardStreak::updateStroke(b);
	}
};

class $modify(PlayerObject) {
	void update(float c) {
		auto thing = getBlendFunc();
		if (m_waveTrail) {
			m_waveTrail->setBlendFunc(thing); // removes the blending of it
		}
		
		PlayerObject::update(c);
	}
};
