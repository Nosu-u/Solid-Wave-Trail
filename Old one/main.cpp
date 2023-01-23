#include <Geode/Geode.hpp>
#include <Geode/Modify.hpp>

USE_GEODE_NAMESPACE();

class $modify(HardStreak) {
	void updateStroke(float b) { // modifies the wave trail every frame
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
