/*
    * Copyright © 2016 Emiliyan Kurtseliyanski a.k.a JunkyBulgaria
    * ------------------------------------------------------------
    * Do whatever you want with this code but DO NOT remove the
    * copyright and respect it's authors.
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"

enum eSpells
{
    SPELL_XXXX = 0000,
};

enum eEvents
{
    EVENT_XXXX,
};

enum eCreatures
{
};

enum eSays
{
    SAY_XXXX,
};

enum eActions
{
    ACTION_XXXX,
};

class rare_mob_urdur_the_cauterizer : public CreatureScript
{
    public:
        rare_mob_urdur_the_cauterizer() : CreatureScript("rare_mob_urdur_the_cauterizer") { }

        struct rare_mob_urdur_the_cauterizerAI : public BossAI
        {
            rare_mob_urdur_the_cauterizerAI(Creature* creature) : BossAI(creature, 0) { }

            EventMap events;

            void Reset()
            {
                events.Reset();
                _Reset();

                //events.ScheduleEvent(EVENT_XXXX, urand(7500, 15000));
            }

            void KilledUnit(Unit* who)
            {
            }

            void EnterCombat(Unit* /*attacker*/)
            {
            }

            void JustDied(Unit* /*killer*/)
            {
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);
                switch (events.ExecuteEvent())
                {
                    case EVENT_XXXX:
                    {
                        events.ScheduleEvent(EVENT_XXXX, urand(7500, 15000));
                        break;
                    }
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new rare_mob_urdur_the_cauterizerAI(creature);
        }
};

void AddSC_rare_mob_urdur_the_cauterizer()
{
    new rare_mob_urdur_the_cauterizer();
}
