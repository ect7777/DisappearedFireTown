#include "character.h"

QString Character::getSkillName(int opt){
    switch (opt) {
    case 1:return "普通攻击\nCP:0";break;
    case 2:return "发怒\nCP:0";break;
    case 3:return "穿心箭\nCP:20";break;
    case 4:return "凝神射击\nCP:15";break;
    case 5:return "散射\nCP:15";break;
    case 6:return "黯灭射击\nCP:100";break;
    case 7:return "绷带处理\nCP:20";break;
    case 14:return "攻守互换\nCP:5";break;
    case 15:return "莽撞\nCP:200";break;
    case 16:return "静观其变\nCP:5";break;
    case 71:return "记住当下\nCP:5";break;
    case 72:return "回忆赋形\nCP:10";break;
    case 73:return "重拾旧志\nCP:10";break;
    case 74:return "时间爆破\nCP:70";break;
    default: return "Error!";break;
    }
}
QString Character::skillsOption(){
    QString text;
    for(int i=0;i<skills.size();i++){
        text+=QString("[%1]%2\n").arg(i).arg(getSkillName(skills[i]));
    }
    return text;
}
/*关于技能ID的说明
 * 1.普通攻击
 * 2.发怒
 * 3.穿心箭
 * 4.凝神射击
 * 5.散射
 * 6.黯灭射击
 * 7.绷带处理
 * 8.强力撕咬
 * 14.攻守互换
 * 15.莽撞
 * 16.静观其变
 */
Character::Character(int setID,QString inname)
{
    CP=0;
    AT=0;
    name=inname;
    ID=setID;
    switch(ID){
    case 0://0号是测试人物ZERO
        picture=QPixmap(":/image/image/zero.png");
        nHP=HP=2000;
        nATK=ATK=177;
        nDEF=DEF=50;
        isenemy=0;
        skills.append(1);skills.append(71);skills.append(72);
        skills.append(73);skills.append(74);
        break;
    case 1://1号是第一章主角，陈刚
        picture=QPixmap(":/character/image/archer.png");
        nHP=HP=1000;
        nATK=ATK=77;
        nDEF=DEF=20;
        isenemy=0;
        skills.append(1);skills.append(3);skills.append(4);skills.append(5);skills.append(6);
        break;
    case 2://防卫队队员
        picture=QPixmap(":/character/image/member.png");
        nHP=HP=600;
        nATK=ATK=50;
        nDEF=DEF=10;
        isenemy=0;
        skills.append(1);skills.append(7);
        break;
    case 3://第二章主角
        picture=QPixmap(":/character/image/hero2.png");
        nHP=HP=500;
        nATK=ATK=10;
        nDEF=DEF=90;
        isenemy=0;
        skills.append(1);skills.append(14);skills.append(15);skills.append(16);skills.append(7);
        break;
    case 4://第二章主角part2
        picture=QPixmap(":/character/image/hero2.png");
        nHP=500;
        HP=251;
        nATK=ATK=180;
        nDEF=DEF=5;
        CP=20;
        isenemy=0;
        skills.append(1);skills.append(14);skills.append(15);skills.append(16);skills.append(7);
        break;
    case 11:
        //11号是第一种敌人，三头犬 拥有 技能 攻击 和 发怒 强力攻击，是一种常见的魔兽，战斗力 较强
        picture=QPixmap(":/character/image/fireDog.png");
        nHP=HP=600;
        nATK=ATK=100;
        nDEF=DEF=0;
        isenemy=1;
        skills.append(1);skills.append(2);skills.append(8);
        break;
    case 12:
        //飞龙 BOSS
        picture=QPixmap(":/character/image/dragon.png");
        nHP=HP=2000;
        nATK=ATK=150;
        nDEF=DEF=20;
        isenemy=1;stage=1;
        skills.append(9);skills.append(10);
        skills.append(11);skills.append(12);
        skills.append(13);
        break;
    case 13://主角父亲
        picture=QPixmap(":/character/image/chiyan.png");
        nHP=HP=10000;
        nATK=ATK=400;
        nDEF=DEF=25;
        isenemy=1;
        skills.append(1);
        skills.append(17);
        skills.append(18);
        skills.append(19);
        break;
    case 14://part2boss
        picture=QPixmap(":/character/image/firewild.png");
        nHP=HP=2000;
        nATK=ATK=100;
        nDEF=DEF=50;
        AT=10;
        CP=20;
        isenemy=1;stage=1;
        skills.append(20);skills.append(21);skills.append(22);skills.append(23);skills.append(24);
        break;
    case 70://灵火，第三章小怪
        picture=QPixmap(":/character/image/fire.png");
        nHP=HP=500;
        nATK=ATK=200;
        nDEF=DEF=10;
        isenemy=1;
        break;
    case 71:
        picture=QPixmap(":/character/image/soulfire.png");
        nHP=HP=7000;
        stage=1;log[0]=0;
        nATK=ATK=200;
        nDEF=DEF=20;
        isenemy=1;
        break;
    }
}
