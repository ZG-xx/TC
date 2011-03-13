/* 
 * Copyright (C) 2011 TrioraCore <http://www.trioracore.ru/>
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * Thanks to the original authors: ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_GOSSIP_H
#define SC_GOSSIP_H

#include "Player.h"
#include "GossipDef.h"
#include "QuestDef.h"

enum GossipTexts
{
    // Gossip Item Text
    GOSSIP_TEXT_BROWSE_GOODS       = -3608000,
    GOSSIP_TEXT_TRAIN              = -3608001,

    GOSSIP_TEXT_BANK               = -3608002,
    GOSSIP_TEXT_IRONFORGE_BANK     = -3608003,
    GOSSIP_TEXT_STORMWIND_BANK     = -3608004,
    GOSSIP_TEXT_WINDRIDER          = -3608005,
    GOSSIP_TEXT_GRYPHON            = -3608006,
    GOSSIP_TEXT_BATHANDLER         = -3608007,
    GOSSIP_TEXT_HIPPOGRYPH         = -3608008,
    GOSSIP_TEXT_ZEPPLINMASTER      = -3608009,
    GOSSIP_TEXT_DEEPRUNTRAM        = -3608010,
    GOSSIP_TEXT_FERRY              = -3608011,
    GOSSIP_TEXT_FLIGHTMASTER       = -3608012,
    GOSSIP_TEXT_AUCTIONHOUSE       = -3608013,
    GOSSIP_TEXT_GUILDMASTER        = -3608014,
    GOSSIP_TEXT_INN                = -3608015,
    GOSSIP_TEXT_MAILBOX            = -3608016,
    GOSSIP_TEXT_STABLEMASTER       = -3608017,
    GOSSIP_TEXT_WEAPONMASTER       = -3608018,
    GOSSIP_TEXT_OFFICERS           = -3608019,
    GOSSIP_TEXT_BATTLEMASTER       = -3608020,
    GOSSIP_TEXT_BARBER             = -3608021,
    GOSSIP_TEXT_CLASSTRAINER       = -3608022,
    GOSSIP_TEXT_PROFTRAINER        = -3608023,
    GOSSIP_TEXT_LEXICON            = -3608024,

    GOSSIP_TEXT_ALTERACVALLEY      = -3608025,
    GOSSIP_TEXT_ARATHIBASIN        = -3608026,
    GOSSIP_TEXT_WARSONGULCH        = -3608027,
    GOSSIP_TEXT_ARENA              = -3608028,
    GOSSIP_TEXT_EYEOFTHESTORM      = -3608029,
    GOSSIP_TEXT_STRANDOFANCIENT    = -3608030,

    GOSSIP_TEXT_DEATH_KNIGHT       = -3608031,
    GOSSIP_TEXT_DRUID              = -3608032,
    GOSSIP_TEXT_HUNTER             = -3608033,
    GOSSIP_TEXT_PRIEST             = -3608034,
    GOSSIP_TEXT_ROGUE              = -3608035,
    GOSSIP_TEXT_WARRIOR            = -3608036,
    GOSSIP_TEXT_PALADIN            = -3608037,
    GOSSIP_TEXT_SHAMAN             = -3608038,
    GOSSIP_TEXT_MAGE               = -3608039,
    GOSSIP_TEXT_WARLOCK            = -3608040,

    GOSSIP_TEXT_ALCHEMY            = -3608041,
    GOSSIP_TEXT_BLACKSMITHING      = -3608042,
    GOSSIP_TEXT_COOKING            = -3608043,
    GOSSIP_TEXT_ENCHANTING         = -3608044,
    GOSSIP_TEXT_ENGINEERING        = -3608045,
    GOSSIP_TEXT_FIRSTAID           = -3608046,
    GOSSIP_TEXT_HERBALISM          = -3608047,
    GOSSIP_TEXT_INSCRIPTION        = -3608048,
    GOSSIP_TEXT_JEWELCRAFTING      = -3608049,
    GOSSIP_TEXT_LEATHERWORKING     = -3608050,
    GOSSIP_TEXT_TAILORING          = -3608051,
    GOSSIP_TEXT_MINING             = -3608052,
    GOSSIP_TEXT_FISHING            = -3608053,
    GOSSIP_TEXT_SKINNING           = -3608054
};

enum eTradeskill
{
// Skill defines
    TRADESKILL_ALCHEMY                  = 1,
    TRADESKILL_BLACKSMITHING            = 2,
    TRADESKILL_COOKING                  = 3,
    TRADESKILL_ENCHANTING               = 4,
    TRADESKILL_ENGINEERING              = 5,
    TRADESKILL_FIRSTAID                 = 6,
    TRADESKILL_HERBALISM                = 7,
    TRADESKILL_LEATHERWORKING           = 8,
    TRADESKILL_POISONS                  = 9,
    TRADESKILL_TAILORING                = 10,
    TRADESKILL_MINING                   = 11,
    TRADESKILL_FISHING                  = 12,
    TRADESKILL_SKINNING                 = 13,
    TRADESKILL_JEWLCRAFTING             = 14,
    TRADESKILL_INSCRIPTION              = 15,

    TRADESKILL_LEVEL_NONE               = 0,
    TRADESKILL_LEVEL_APPRENTICE         = 1,
    TRADESKILL_LEVEL_JOURNEYMAN         = 2,
    TRADESKILL_LEVEL_EXPERT             = 3,
    TRADESKILL_LEVEL_ARTISAN            = 4,
    TRADESKILL_LEVEL_MASTER             = 5,
    TRADESKILL_LEVEL_GRAND_MASTER       = 6,

// Gossip defines
    GOSSIP_ACTION_TRADE                 = 1,
    GOSSIP_ACTION_TRAIN                 = 2,
    GOSSIP_ACTION_TAXI                  = 3,
    GOSSIP_ACTION_GUILD                 = 4,
    GOSSIP_ACTION_BATTLE                = 5,
    GOSSIP_ACTION_BANK                  = 6,
    GOSSIP_ACTION_INN                   = 7,
    GOSSIP_ACTION_HEAL                  = 8,
    GOSSIP_ACTION_TABARD                = 9,
    GOSSIP_ACTION_AUCTION               = 10,
    GOSSIP_ACTION_INN_INFO              = 11,
    GOSSIP_ACTION_UNLEARN               = 12,
    GOSSIP_ACTION_INFO_DEF              = 1000,

    GOSSIP_SENDER_MAIN                  = 1,
    GOSSIP_SENDER_INN_INFO              = 2,
    GOSSIP_SENDER_INFO                  = 3,
    GOSSIP_SENDER_SEC_PROFTRAIN         = 4,
    GOSSIP_SENDER_SEC_CLASSTRAIN        = 5,
    GOSSIP_SENDER_SEC_BATTLEINFO        = 6,
    GOSSIP_SENDER_SEC_BANK              = 7,
    GOSSIP_SENDER_SEC_INN               = 8,
    GOSSIP_SENDER_SEC_MAILBOX           = 9,
    GOSSIP_SENDER_SEC_STABLEMASTER      = 10
};

extern uint32 GetSkillLevel(Player *player,uint32 skill);

// Defined fuctions to use with player.

// Icon Id
// Text
// Sender(this is to identify the current Menu with this item)
// Option id (identifies this Menu Item)
// Text to be displayed in pop up box
// Money value in pop up box
// Coded
#define ADD_GOSSIP_ITEM(uiIcon, chrText, uiSender, uiOptionId)   PlayerTalkClass->GetGossipMenu().AddMenuItem(uiIcon, chrText, uiSender, uiOptionId, "", 0)
#define ADD_GOSSIP_ITEM_ID(uiIcon, iTextId, uiSender, uiOptionId)   PlayerTalkClass->GetGossipMenu().AddMenuItem(uiIcon, iTextId, uiSender, uiOptionId, 0, 0)
#define ADD_GOSSIP_ITEM_EXTENDED(uiIcon, chrText, uiSender, uiOptionId, chrBoxMessage, uiBoxMoney, bCode)   PlayerTalkClass->GetGossipMenu().AddMenuItem(uiIcon, chrText, uiSender, uiOptionId, chrBoxMessage, uiBoxMoney, bCode)

// This fuction Sends the current menu to show to client, uiTextId - NPCTEXTID(uint32) , uiGuid - npc guid(uint64)
#define SEND_GOSSIP_MENU(uiTextId, uiGuid)      PlayerTalkClass->SendGossipMenu(uiTextId, uiGuid)

// This fuction shows POI(point of interest) to client.
// a - position X
// b - position Y
// c - Icon Id
// d - Flags
// e - Data
// f - Location Name
#define SEND_POI(a,b,c,d,e,f)      PlayerTalkClass->SendPointOfInterest(a,b,c,d,e,f)

// Closes the Menu
#define CLOSE_GOSSIP_MENU()        PlayerTalkClass->CloseGossip()

// Fuction to tell to client the details
// a - quest object
// b - npc guid(uint64)
// c - Activate accept(bool)
#define SEND_QUEST_DETAILS(a,b,c)  PlayerTalkClass->SendQuestDetails(a,b,c)

// Fuction to tell to client the requested items to complete quest
// a - quest object
// b - npc guid(uint64)
// c - Iscompletable(bool)
// d - close at cancel(bool) - in case single incomplite ques
#define SEND_REQUESTEDITEMS(a,b,c,d) PlayerTalkClass->SendRequestedItems(a,b,c,d)

// Fuctions to send NPC lists, a - is always the npc guid(uint64)
#define SEND_VENDORLIST(a)         GetSession()->SendListInventory(a)
#define SEND_TRAINERLIST(a)        GetSession()->SendTrainerList(a)

// Ressurect's the player if is dead.
#define SEND_SPRESURRECT()         GetSession()->SendSpiritResurrect()

// Get the player's honor rank.
#define GET_HONORRANK()            GetHonorRank()
// -----------------------------------

// defined fuctions to use with Creature

#define QUEST_DIALOG_STATUS(a,b,c)   GetSession()->getDialogStatus(a,b,c)
#endif
