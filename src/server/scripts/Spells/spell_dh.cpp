/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Scripts for spells with SPELLFAMILY_DEMONHUNTER and SPELLFAMILY_GENERIC spells used by Demon Hunter players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dh_".
 */

#include "Player.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellHistory.h"
#include "SpellAuraEffects.h"
#include "GridNotifiers.h"

enum DemonHunterSpells
{
};

// Glide - 131347
class spell_dh_glide : public SpellScriptLoader
{
public:
	spell_dh_glide() : SpellScriptLoader("spell_dh_glide") { }

	class spell_dh_glide_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_dh_glide_SpellScript);

		SpellCastResult CheckCast()
		{
			if (Unit* caster = GetCaster())
				if (!caster->IsFalling())
					return SPELL_FAILED_NOT_ON_GROUND;			
			return SPELL_CAST_OK;
		}

		void Register() override
		{
			OnCheckCast += SpellCheckCastFn(spell_dh_glide_SpellScript::CheckCast);
		}
	};

	SpellScript* GetSpellScript() const override
	{
		return new spell_dh_glide_SpellScript();
	}
};

void AddSC_demon_hunter_spell_scripts()
{
	new spell_dh_glide();
}
