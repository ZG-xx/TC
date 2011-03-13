/*
 * Copyright (C) 2011 TrioraCore <http://www.trioracore.ru/>
 */
 
#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "Chat.h"

//Transfer players
class pl_transfer_commandscript : public CommandScript
{
public:
    pl_transfer_commandscript() : CommandScript("pl_transfer_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand typeCommandTable[] =
        {
            { "mana",              SEC_ADMINISTRATOR,      false, &HandleTransItemManaCommand,        "", NULL },
            { "agi",               SEC_ADMINISTRATOR,      false, &HandleTransItemAgilCommand,        "", NULL },
            { "str",               SEC_ADMINISTRATOR,      false, &HandleTransItemStrCommand,         "", NULL },
            { "stam",              SEC_ADMINISTRATOR,      false, &HandleTransItemStamCommand,        "", NULL },
            { "",                  SEC_ADMINISTRATOR,      false, &HandleTransItemManaCommand,        "", NULL },
            { NULL,                0,                      false, NULL,                               "", NULL }
        };
        static ChatCommand transCommandTable[] =
        {
            { "item",              SEC_ADMINISTRATOR,      false, NULL,                   "", typeCommandTable },
            { NULL,                0,                      false, NULL,                               "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "trans",             SEC_ADMINISTRATOR,      false, NULL,                  "", transCommandTable },
            { NULL,                0,                      false, NULL,                               "", NULL }
        };
        return commandTable;
    }
    
    static bool HandleTransItemAgilCommand(ChatHandler* handler, const char* args)
    {
        Player* targetPlayer = handler->getSelectedPlayer();

        uint32 count = 1;
        
		if (!targetPlayer)
            targetPlayer = handler->GetSession()->GetPlayer();
        
        static const char *HuntItemList[] =
        {
            "43447",//Шлем
            "43449",//Плечи
            "43445",//Грудь
            "43444",//Наручи
            "43446",//Перчи
            "43442",//Пояс
            "43448",//Штаны
            "43443",//Боты
            "35590",//Лук
            "37065",//Мечь
            "0"
        };
        
        static const char *RogueItemList[] =
        {
            "43260",//Шлем
            "43433",//Плечи
            "43434",//Грудь
            "43435",//Наручи
            "43436",//Перчи
            "43437",//Пояс
            "43438",//Штаны
            "43439",//Боты
            "36944",//Кинжал
            "36944",//Кинжал
            "0"
        };
        
        static const char *DruidItemList[] =
        {
            "43260",//Шлем
            "43433",//Плечи
            "43434",//Грудь
            "43435",//Наручи
            "43436",//Перчи
            "43437",//Пояс
            "43438",//Штаны
            "43439",//Боты
            "37099",//Посох
            "0"
        };
        
        uint32 ItemIter = 0;
        
        switch (targetPlayer->getClass())
        {
            case 3:
                while (strcmp(HuntItemList[ItemIter], "0"))
                {
                    uint32 ItemId = atol((char*)HuntItemList[ItemIter++]);
            
                    ItemPosCountVec dest;

                    ItemPrototype const *pProto = sObjectMgr->GetItemPrototype(ItemId);
            
                    if (!pProto)
                    {
                        handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, ItemId);
                        handler->SetSentErrorMessage(true);
                        return false;
                    }
            
                    uint8 msg = targetPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ItemId, count, false);
            
                    if (msg == EQUIP_ERR_OK)
                    {
                        Item* item = targetPlayer->StoreNewItem(dest, ItemId, true, Item::GenerateItemRandomPropertyId(ItemId));
                        targetPlayer->SendNewItem(item,count,false,true);
                        targetPlayer->SaveToDB();
                    }
                    else
                    {
                        handler->PSendSysMessage(LANG_COMMAND_NOT_ADDING, pProto->Name1, count);
                        return true;
                    }
                }
                break;
            case 4:
                while (strcmp(RogueItemList[ItemIter], "0"))
                {
                    uint32 ItemId = atol((char*)RogueItemList[ItemIter++]);
            
                    ItemPosCountVec dest;

                    ItemPrototype const *pProto = sObjectMgr->GetItemPrototype(ItemId);
            
                    if (!pProto)
                    {
                        handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, ItemId);
                        handler->SetSentErrorMessage(true);
                        return false;
                    }
            
                    uint8 msg = targetPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ItemId, count, false);
            
                    if (msg == EQUIP_ERR_OK)
                    {
                        Item* item = targetPlayer->StoreNewItem(dest, ItemId, true, Item::GenerateItemRandomPropertyId(ItemId));
                        targetPlayer->SendNewItem(item,count,false,true);
                        targetPlayer->SaveToDB();
                    }
                    else
                    {
                        handler->PSendSysMessage(LANG_COMMAND_NOT_ADDING, pProto->Name1, count);
                        return true;
                    }
                }
                break;
            case 11:
                while (strcmp(DruidItemList[ItemIter], "0"))
                {
                    uint32 ItemId = atol((char*)DruidItemList[ItemIter++]);
            
                    ItemPosCountVec dest;

                    ItemPrototype const *pProto = sObjectMgr->GetItemPrototype(ItemId);
            
                    if (!pProto)
                    {
                        handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, ItemId);
                        handler->SetSentErrorMessage(true);
                        return false;
                    }
            
                    uint8 msg = targetPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ItemId, count, false);
            
                    if (msg == EQUIP_ERR_OK)
                    {
                        Item* item = targetPlayer->StoreNewItem(dest, ItemId, true, Item::GenerateItemRandomPropertyId(ItemId));
                        targetPlayer->SendNewItem(item,count,false,true);
                        targetPlayer->SaveToDB();
                    }
                    else
                    {
                        handler->PSendSysMessage(LANG_COMMAND_NOT_ADDING, pProto->Name1, count);
                        return true;
                    }
                }
                break;
        }
        return true;
    }
    
    static bool HandleTransItemManaCommand(ChatHandler* handler, const char* args)
    {
        Player* targetPlayer = handler->getSelectedPlayer();
        
        uint32 count = 1;
        
        if (!targetPlayer)
            targetPlayer = handler->GetSession()->GetPlayer();
        
        static const char *PaladinItemList[] =
        {
            "42723",//Наручи 
            "42727",//Плечи
            "42724",//Перчи
            "42730",//Боты
            "42729",//Пояс
            "42726",//Штаны
            "42725",//Грудь
            "42728",//Шлем
            "42222",//Правая рука
            "41188",//Две руки
            "37061",//Щит
            "0"
        };
        
        static const char *PriestItemList[] =
        {
            "43972",//Грудь
            "43969",//Пояс
            "43974",//Наручи
            "43973",//Плечи
            "43970",//Боты
            "41516",//Перчи
            "43971",//Шлем
            "43975",//Штаны
            "37099",//Посох
            "0"
        };
        
        static const char *ShamanItemList[] =
        {
            "43455",//Шлем
            "43457",//Плечи
            "43453",//Грудь
            "43452",//Наручи
            "43454",//Перчи
            "43450",//Пояс
            "43456",//Штаны
            "43451",//Боты
            "37681",//Правая рука
            "37061",//Щит
            "0"
        };
        
        static const char *MageItemList[] =
        {
            "43972",//Грудь
            "43969",//Пояс
            "43974",//Наручи
            "43973",//Плечи
            "43970",//Боты
            "41516",//Перчи
            "43971",//Шлем
            "43975",//Штаны
            "37099",//Посох
            "0"
        };
        
        static const char *WarlockItemList[] =
        {
            "43972",//Грудь
            "43969",//Пояс
            "43974",//Наручи
            "43973",//Плечи
            "43970",//Боты
            "41516",//Перчи
            "43971",//Шлем
            "43975",//Штаны
            "37099",//Посох
            "0"
        };
        
        static const char *DruidItemList[] =
        {
            "43261",
            "43262",
            "43263",
            "43264",
            "43265",
            "43266",
            "43271",
            "43273",
            "37099",//Посох
            "0"
        };
        
        uint32 ItemIter = 0;
        
        switch (targetPlayer->getClass())
        {
            case 2:
                while (strcmp(PaladinItemList[ItemIter], "0"))
                {
                    uint32 ItemId = atol((char*)PaladinItemList[ItemIter++]);
            
                    ItemPosCountVec dest;

                    ItemPrototype const *pProto = sObjectMgr->GetItemPrototype(ItemId);
            
                    if (!pProto)
                    {
                        handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, ItemId);
                        handler->SetSentErrorMessage(true);
                        return false;
                    }
            
                    uint8 msg = targetPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ItemId, count, false);
            
                    if (msg == EQUIP_ERR_OK)
                    {
                        Item* item = targetPlayer->StoreNewItem(dest, ItemId, true, Item::GenerateItemRandomPropertyId(ItemId));
                        targetPlayer->SendNewItem(item,count,false,true);
                        targetPlayer->SaveToDB();
                    }
                    else
                    {
                        handler->PSendSysMessage(LANG_COMMAND_NOT_ADDING, pProto->Name1, count);
                        return true;
                    }
                }
                break;
            case 5:
                while (strcmp(PriestItemList[ItemIter], "0"))
                {
                    uint32 ItemId = atol((char*)PriestItemList[ItemIter++]);
            
                    ItemPosCountVec dest;

                    ItemPrototype const *pProto = sObjectMgr->GetItemPrototype(ItemId);
            
                    if (!pProto)
                    {
                        handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, ItemId);
                        handler->SetSentErrorMessage(true);
                        return false;
                    }
            
                    uint8 msg = targetPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ItemId, count, false);
            
                    if (msg == EQUIP_ERR_OK)
                    {
                        Item* item = targetPlayer->StoreNewItem(dest, ItemId, true, Item::GenerateItemRandomPropertyId(ItemId));
                        targetPlayer->SendNewItem(item,count,false,true);
                        targetPlayer->SaveToDB();
                    }
                    else
                    {
                        handler->PSendSysMessage(LANG_COMMAND_NOT_ADDING, pProto->Name1, count);
                        return true;
                    }
                }
                break;
            case 7:
                while (strcmp(ShamanItemList[ItemIter], "0"))
                {
                    uint32 ItemId = atol((char*)ShamanItemList[ItemIter++]);
            
                    ItemPosCountVec dest;

                    ItemPrototype const *pProto = sObjectMgr->GetItemPrototype(ItemId);
            
                    if (!pProto)
                    {
                        handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, ItemId);
                        handler->SetSentErrorMessage(true);
                        return false;
                    }
            
                    uint8 msg = targetPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ItemId, count, false);
            
                    if (msg == EQUIP_ERR_OK)
                    {
                        Item* item = targetPlayer->StoreNewItem(dest, ItemId, true, Item::GenerateItemRandomPropertyId(ItemId));
                        targetPlayer->SendNewItem(item,count,false,true);
                        targetPlayer->SaveToDB();
                    }
                    else
                    {
                        handler->PSendSysMessage(LANG_COMMAND_NOT_ADDING, pProto->Name1, count);
                        return true;
                    }
                }
                break;
            case 8:
                while (strcmp(MageItemList[ItemIter], "0"))
                {
                    uint32 ItemId = atol((char*)MageItemList[ItemIter++]);
            
                    ItemPosCountVec dest;

                    ItemPrototype const *pProto = sObjectMgr->GetItemPrototype(ItemId);
            
                    if (!pProto)
                    {
                        handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, ItemId);
                        handler->SetSentErrorMessage(true);
                        return false;
                    }
            
                    uint8 msg = targetPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ItemId, count, false);
            
                    if (msg == EQUIP_ERR_OK)
                    {
                        Item* item = targetPlayer->StoreNewItem(dest, ItemId, true, Item::GenerateItemRandomPropertyId(ItemId));
                        targetPlayer->SendNewItem(item,count,false,true);
                        targetPlayer->SaveToDB();
                    }
                    else
                    {
                        handler->PSendSysMessage(LANG_COMMAND_NOT_ADDING, pProto->Name1, count);
                        return true;
                    }
                }
                break;
            case 9:
                while (strcmp(WarlockItemList[ItemIter], "0"))
                {
                    uint32 ItemId = atol((char*)WarlockItemList[ItemIter++]);
            
                    ItemPosCountVec dest;

                    ItemPrototype const *pProto = sObjectMgr->GetItemPrototype(ItemId);
            
                    if (!pProto)
                    {
                        handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, ItemId);
                        handler->SetSentErrorMessage(true);
                        return false;
                    }
            
                    uint8 msg = targetPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ItemId, count, false);
            
                    if (msg == EQUIP_ERR_OK)
                    {
                        Item* item = targetPlayer->StoreNewItem(dest, ItemId, true, Item::GenerateItemRandomPropertyId(ItemId));
                        targetPlayer->SendNewItem(item,count,false,true);
                        targetPlayer->SaveToDB();
                    }
                    else
                    {
                        handler->PSendSysMessage(LANG_COMMAND_NOT_ADDING, pProto->Name1, count);
                        return true;
                    }
                }
                break;
            case 11:
                while (strcmp(DruidItemList[ItemIter], "0"))
                {
                    uint32 ItemId = atol((char*)DruidItemList[ItemIter++]);
            
                    ItemPosCountVec dest;

                    ItemPrototype const *pProto = sObjectMgr->GetItemPrototype(ItemId);
            
                    if (!pProto)
                    {
                        handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, ItemId);
                        handler->SetSentErrorMessage(true);
                        return false;
                    }
            
                    uint8 msg = targetPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ItemId, count, false);
            
                    if (msg == EQUIP_ERR_OK)
                    {
                        Item* item = targetPlayer->StoreNewItem(dest, ItemId, true, Item::GenerateItemRandomPropertyId(ItemId));
                        targetPlayer->SendNewItem(item,count,false,true);
                        targetPlayer->SaveToDB();
                    }
                    else
                    {
                        handler->PSendSysMessage(LANG_COMMAND_NOT_ADDING, pProto->Name1, count);
                        return true;
                    }
                }
                break;
        }
        return true;
    }
    
    static bool HandleTransItemStrCommand(ChatHandler* handler, const char* args)
    {
        Player* targetPlayer = handler->getSelectedPlayer();
        
        uint32 count = 1;
        
        if (!targetPlayer)
            targetPlayer = handler->GetSession()->GetPlayer();
        
        static const char *WarItemList[] =
        {
            "41355",//Наручи 
            "41344",//Шлем
            "41353",//Грудь (на танка)
            "41349",//Перчи (на танка)
            "41351",//Плечи (На танка)
            "41352",//Пояс (На танка)
            "41347",//Штаны (На танка)
            "41348",//Боты (На танка)
            "37179",//Правая рука
            "37107",//Щит
            "44708",//Две руки
            "0"
        };
        
        static const char *PalItemList[] =
        {
            "41355",//Наручи 
            "41344",//Шлем
            "41353",//Грудь (на танка)
            "41349",//Перчи (на танка)
            "41351",//Плечи (На танка)
            "41352",//Пояс (На танка)
            "41347",//Штаны (На танка)
            "41348",//Боты (На танка)
            "37179",//Правая рука
            "37107",//Щит
            "44708",//Две руки
            "0"
        };
        
        static const char *DKItemList[] =
        {
            "41355",//Наручи 
            "41344",//Шлем
            "41353",//Грудь (на танка)
            "41349",//Перчи (на танка)
            "41351",//Плечи (На танка)
            "41352",//Пояс (На танка)
            "41347",//Штаны (На танка)
            "41348",//Боты (На танка)
            "44708",//Две руки
            "0"
        };
        
        uint32 ItemIter = 0;
        
        switch (targetPlayer->getClass())
        {
            case 1:
                while (strcmp(WarItemList[ItemIter], "0"))
                {
                    uint32 ItemId = atol((char*)WarItemList[ItemIter++]);
            
                    ItemPosCountVec dest;

                    ItemPrototype const *pProto = sObjectMgr->GetItemPrototype(ItemId);
            
                    if (!pProto)
                    {
                        handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, ItemId);
                        handler->SetSentErrorMessage(true);
                        return false;
                    }
            
                    uint8 msg = targetPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ItemId, count, false);
            
                    if (msg == EQUIP_ERR_OK)
                    {
                        Item* item = targetPlayer->StoreNewItem(dest, ItemId, true, Item::GenerateItemRandomPropertyId(ItemId));
                        targetPlayer->SendNewItem(item,count,false,true);
                        targetPlayer->SaveToDB();
                    }
                    else
                    {
                        handler->PSendSysMessage(LANG_COMMAND_NOT_ADDING, pProto->Name1, count);
                        return true;
                    }
                }
                break;
            case 2:
                while (strcmp(PalItemList[ItemIter], "0"))
                {
                    uint32 ItemId = atol((char*)PalItemList[ItemIter++]);
            
                    ItemPosCountVec dest;

                    ItemPrototype const *pProto = sObjectMgr->GetItemPrototype(ItemId);
            
                    if (!pProto)
                    {
                        handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, ItemId);
                        handler->SetSentErrorMessage(true);
                        return false;
                    }
            
                    uint8 msg = targetPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ItemId, count, false);
            
                    if (msg == EQUIP_ERR_OK)
                    {
                        Item* item = targetPlayer->StoreNewItem(dest, ItemId, true, Item::GenerateItemRandomPropertyId(ItemId));
                        targetPlayer->SendNewItem(item,count,false,true);
                        targetPlayer->SaveToDB();
                    }
                    else
                    {
                        handler->PSendSysMessage(LANG_COMMAND_NOT_ADDING, pProto->Name1, count);
                        return true;
                    }
                }
                break;
            case 6:
                while (strcmp(DKItemList[ItemIter], "0"))
                {
                    uint32 ItemId = atol((char*)DKItemList[ItemIter++]);
            
                    ItemPosCountVec dest;

                    ItemPrototype const *pProto = sObjectMgr->GetItemPrototype(ItemId);
            
                    if (!pProto)
                    {
                        handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, ItemId);
                        handler->SetSentErrorMessage(true);
                        return false;
                    }
            
                    uint8 msg = targetPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ItemId, count, false);
            
                    if (msg == EQUIP_ERR_OK)
                    {
                        Item* item = targetPlayer->StoreNewItem(dest, ItemId, true, Item::GenerateItemRandomPropertyId(ItemId));
                        targetPlayer->SendNewItem(item,count,false,true);
                        targetPlayer->SaveToDB();
                    }
                    else
                    {
                        handler->PSendSysMessage(LANG_COMMAND_NOT_ADDING, pProto->Name1, count);
                        return true;
                    }
                }
                break;
        }
        return true;
    }
    
    static bool HandleTransItemStamCommand(ChatHandler* handler, const char* args)
    {
        Player* targetPlayer = handler->getSelectedPlayer();
        
        uint32 count = 1;
        
        if (!targetPlayer)
            targetPlayer = handler->GetSession()->GetPlayer();
            
        static const char *WarItemList[] =
        {
            "41354",//Наручи    
            "41351",//Плечи
            "41349",//Перчи
            "41348",//Боты
            "41352",//Пояс
            "41347",//Штаны
            "41353",//Грудь
            "41350",//Шлем
            "37179",//Правая рука
            "37107",//Щит
            "44708",//Две руки
            "0"
        };
        
        static const char *PalItemList[] =
        {
            "41354",//Наручи 
            "41351",//Плечи
            "41349",//Перчи
            "41348",//Боты
            "41352",//Пояс
            "41347",//Штаны
            "41353",//Грудь
            "41350",//Шлем
            "37179",//Правая рука
            "37107",//Щит
            "44708",//Две руки
            "0"
        };
        
        static const char *DKItemList[] =
        {
            "41354",//Наручи 
            "41351",//Плечи
            "41349",//Перчи
            "41348",//Боты
            "41352",//Пояс
            "41347",//Штаны
            "41353",//Грудь
            "41350",//Шлем
            "44708",//Две руки
            "0"
        };
        
        uint32 ItemIter = 0;
        
        switch (targetPlayer->getClass())
        {
            case 1:
                while (strcmp(WarItemList[ItemIter], "0"))
                {
                    uint32 ItemId = atol((char*)WarItemList[ItemIter++]);
            
                    ItemPosCountVec dest;

                    ItemPrototype const *pProto = sObjectMgr->GetItemPrototype(ItemId);
            
                    if (!pProto)
                    {
                        handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, ItemId);
                        handler->SetSentErrorMessage(true);
                        return false;
                    }
            
                    uint8 msg = targetPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ItemId, count, false);
            
                    if (msg == EQUIP_ERR_OK)
                    {
                        Item* item = targetPlayer->StoreNewItem(dest, ItemId, true, Item::GenerateItemRandomPropertyId(ItemId));
                        targetPlayer->SendNewItem(item,count,false,true);
                        targetPlayer->SaveToDB();
                    }
                    else
                    {
                        handler->PSendSysMessage(LANG_COMMAND_NOT_ADDING, pProto->Name1, count);
                        return true;
                    }
                }
                break;
            case 2:
                while (strcmp(PalItemList[ItemIter], "0"))
                {
                    uint32 ItemId = atol((char*)PalItemList[ItemIter++]);
            
                    ItemPosCountVec dest;

                    ItemPrototype const *pProto = sObjectMgr->GetItemPrototype(ItemId);
            
                    if (!pProto)
                    {
                        handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, ItemId);
                        handler->SetSentErrorMessage(true);
                        return false;
                    }
            
                    uint8 msg = targetPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ItemId, count, false);
            
                    if (msg == EQUIP_ERR_OK)
                    {
                        Item* item = targetPlayer->StoreNewItem(dest, ItemId, true, Item::GenerateItemRandomPropertyId(ItemId));
                        targetPlayer->SendNewItem(item,count,false,true);
                        targetPlayer->SaveToDB();
                    }
                    else
                    {
                        handler->PSendSysMessage(LANG_COMMAND_NOT_ADDING, pProto->Name1, count);
                        return true;
                    }
                }
                break;
            case 6:
                while (strcmp(DKItemList[ItemIter], "0"))
                {
                    uint32 ItemId = atol((char*)DKItemList[ItemIter++]);
            
                    ItemPosCountVec dest;

                    ItemPrototype const *pProto = sObjectMgr->GetItemPrototype(ItemId);
            
                    if (!pProto)
                    {
                        handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, ItemId);
                        handler->SetSentErrorMessage(true);
                        return false;
                    }
            
                    uint8 msg = targetPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ItemId, count, false);
            
                    if (msg == EQUIP_ERR_OK)
                    {
                        Item* item = targetPlayer->StoreNewItem(dest, ItemId, true, Item::GenerateItemRandomPropertyId(ItemId));
                        targetPlayer->SendNewItem(item,count,false,true);
                        targetPlayer->SaveToDB();
                    }
                    else
                    {
                        handler->PSendSysMessage(LANG_COMMAND_NOT_ADDING, pProto->Name1, count);
                        return true;
                    }
                }
                break;
        }
        return true;
    }
};

void AddSC_pl_transfer_commandscript()
{
    new pl_transfer_commandscript();
}
