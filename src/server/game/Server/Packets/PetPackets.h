/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef PetPackets_h__
#define PetPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "Unit.h"

namespace WorldPackets
{
    namespace Pet
    {
        struct Pet
        {
            ObjectGuid Guid;
            uint32 Species = 0;
            uint32 CreatureID = 0;
            uint16 Level = 0;
            uint16 Exp = 0;
            uint16 Flags = 0;
            uint32 Power = 0;
            uint32 Health = 0;
            uint32 MaxHealth = 0;
            uint32 Speed = 0;
            uint8 Quality = 0;
            ObjectGuid Owner;
            std::string Name;
        };

		class PetAbandon final : public ClientPacket
		{
		public:
			PetAbandon(WorldPacket&& packet) : ClientPacket(CMSG_PET_ABANDON, std::move(packet)) { }

			void Read() override;

			ObjectGuid PetGuid;
		};
		/*
        struct PetSlot
        {
            Pet pet;
            uint8 Index = 0;
            bool Locked = true;
        };
		
        class PetModifyName final : public ClientPacket
        {
        public:
            PetModifyName(WorldPacket&& packet) : ClientPacket(CMSG_BATTLE_PET_MODIFY_NAME, std::move(packet)) { }

            void Read() override;

            ObjectGuid PetGuid;
            std::string Name;
            DeclinedName Declined;
        };

        class BattlePetDeletePet final : public ClientPacket
        {
        public:
            BattlePetDeletePet(WorldPacket&& packet) : ClientPacket(CMSG_BATTLE_PET_DELETE_PET, std::move(packet)) { }

            void Read() override;

            ObjectGuid PetGuid;
        };*/
    }
}

#endif // PetPackets_h__
