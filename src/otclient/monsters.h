/*
 * Copyright (c) 2010-2012 OTClient <https://github.com/edubart/otclient>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef MONSTERS_H
#define MONSTERS_H

#include "declarations.h"
#include <framework/luaengine/luaobject.h>
#include "outfit.h"

class MonsterType : public LuaObject
{
public:
    MonsterType() { }
    MonsterType(const std::string& name)
        : m_name(name) { }

    void setPos(const Position& pos) { m_pos = pos; }
    void setName(const std::string& name) { m_name = name; }
    void setOutfit(const Outfit& o) { m_outfit = o; }

    std::string getName() { return m_name; }
    Position getPos() { return m_pos; }
    Outfit getOutfit() { return m_outfit; }

private:
    Position m_pos;
    std::string m_name;
    Outfit m_outfit;
};

class Monsters
{
public:
	void clear() { m_monsters.clear(); }

	void loadMonsters(const std::string& file);
    void loadSingleMonster(const std::string& file, const MonsterTypePtr& m = nullptr);

    MonsterTypePtr getMonster(const std::string& name);
    MonsterTypePtr getMonsterByPos(const Position& pos);

	bool isLoaded() const { return m_loaded; }
private:
    std::vector<MonsterTypePtr> m_monsters;
    bool m_loaded;
};

#endif
