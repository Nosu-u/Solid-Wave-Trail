#include <Geode/Geode.hpp>
#include <Geode/Modify.hpp>

USE_GEODE_NAMESPACE();

class $modify(HardStreak) {
	void updateStroke(float b) { // modifies the wave trail every frame
		m_isSolid = true; // makes it be a one color
		this->setBlendFunc(kCCBlendFuncDisable); // removes the blending of it
		this->setOpacity(255); // so the fade out dont look weird
		
		HardStreak::updateStroke(b);
	}
};

class $modify(PlayLayer) {
	void destroyPlayer(PlayerObject* p, GameObject* g) {
		auto fadeOut = CCFadeOut::create(0.01); // creates the fade out because its broken for some reason
		
		p->m_regularTrail->runAction(fadeOut); // applies the fade
		
	PlayLayer::destroyPlayer(p,g);
	}
};
