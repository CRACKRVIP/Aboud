#include <android/input.h>
#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_android.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include "KittyMemory/MemoryPatch.h"
#include "Iconcpp.h"
#include "ImguiPP.h"
#include "Menu.h"
#include "Font.h"
#include "Icon.h"
#include "Helper/fake_dlfcn.h"
#include "Helper/Includes.h"
#include "Helper/plthook.h"
#include "Helper/json.hpp"
#include "Helper/Items.h"
#include "StrEnc.h"
#include "Spoof.h"
#include "Tools.h"
#include "SDK.hpp"
//#include "font3.h"
#include "base64/base64.h"
#include "obfuscate.h"
#include "Dobby/dobby.h"
#include "cyrillic.h"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "bold.hpp"
#include "imgui/imgui_internal.h"
//#include "Oxorany/oxorany.h"
#include "Snowflake.hpp"
#include "Snowflake.cpp"

static int style_idx = 3;

bool show_esp_window = true;
bool show_another_window = true;
bool show_items_window = false;
bool show_aimbot_window = false;
bool show_memory_window = false;
//Key expired
std::string KeySlot = "";
std::string FlotingText = "";
std::string expiredDate = " %s"; 
//Key expired 
float accent_color[4] = { 0.745f, 0.151f, 0.151f, 1.000f };
bool WriteAddr(void *addr, void *buffer, size_t length) {
    unsigned long page_size = sysconf(_SC_PAGESIZE);
    unsigned long size = page_size * sizeof(uintptr_t);
    return mprotect((void *) ((uintptr_t) addr - ((uintptr_t) addr % page_size) - page_size), (size_t) size, PROT_EXEC | PROT_READ | PROT_WRITE) == 0 && memcpy(addr, buffer, length) != 0;
}

template<typename T>
void Write(uintptr_t addr, T value) {
    WriteAddr((void *) addr, &value, sizeof(T));
}

using json = nlohmann::json;
using namespace SDK;
#include <curl/curl.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

// ======================================================================= //
bool initImGui = false;

float FOVSize = 0;
char extra[32];
int screenWidth = -1, glWidth, screenHeight = -1, glHeight;
float density = -1;

json sniper1;
json rifle1;
json sub1;
json ammo1;
json scope1;
json atta1;
json mag1;
json medic1;
json armor1;
json grenade1;
json items_data;

time_t rng = 0;
std::vector<Snowflake::Snowflake> Snow;
std::string expiretime = "";
std::string g_Token, g_Auth;
bool bValid = false;
static std::string EXP = " 00:00:00:00:00:00:00";
bool bypass = true;
bool bypass1 = true;
bool bypass2 = true;
bool bypass3 = true;
bool Bypass = true;
bool Bypass1 = true;
bool Bypass2 = true;
bool Bypass3 = true;
/*bool Bypass4 = true;
bool Bypasss = true;
bool Bypass5 = true;*/
bool Bypass6 = true;
bool Bypass7 = true;
bool Bypass8 = true;
bool Bypass13 = true;
/*bool bypass1 = true;
bool bypass2 = true; 
bool bypass3 = true;*/
bool 平板视角;
int AutoTargetChoose = 1;

bool fov = false;



bool 防封菜单 = false;
bool 枪械减后;
float 开火距离 = 50.0f;
bool 自动开火 = false;
bool fixed = true;
bool 初始化 = false;
bool 忽略倒地 = false;
bool 忽略人机 = false;
bool 自瞄 = false;
bool 载具 = false;
bool 飞机 = false;
bool 空投 = false;
float 自瞄距离 = 200;
float FOV = 250.0f;
#define SLEEP_TIME 1000LL / 120LL
uintptr_t ANOGS;
uintptr_t flutter;
uintptr_t EGL;
uintptr_t UE4;
uintptr_t g_gcloud;
uintptr_t g_UE4;
uintptr_t HOOK_LIB;
uintptr_t Anogs;
uintptr_t g_Anogs;
uintptr_t anogs;
uintptr_t g_anogs;
uintptr_t INTLFoundation;
uintptr_t INTLCompliance;
uintptr_t ITOP;
uintptr_t swappy;
uintptr_t AimBullet_Offset;
uintptr_t GWorld_Offset, GUObjectArray_Offset, SilentAim_Offset;
// ======================================================================== //
static float isRed = 0.0f, isGreen = 0.01f, isBlue = 0.0f;
enum EAim {
  Distance = 0,
  Croshhair = 1
};


enum EAimTarget {
    Head = 0,
    Chest = 1,
    Auto = 2
};

enum EAutoTargetChoose {
    

};

enum EAimTrigger {
    None = 0,
    Shooting = 1,
    Scoping = 2,
    Both = 3,
    Any = 4
};

enum EEsp {
  EspNone =0,
  EspNone1 =0,
  EspTop = 1,
  EspTop1 = 1,
  EspMid = 2,
  EspMid1 = 2,
  EspBottom = 3,
  EspBottom1 = 3
};

std::map<int, bool> Items;
std::map<int, float *> ItemColors;

struct sConfig {
	bool Bypass = true;
	bool Bypass4;
	bool TSSBypass;
	bool GLBypass;
	bool CrashFix;
	bool LogoKmkl;
	bool BypassK;
	float Skeleton1;
	bool Box;
	float Line1;
	float Line;
	bool Less1;
	bool Box1;
	bool Bypass1;
	float AimBotSpeed;
	bool Bypass2;
	bool Bypass3;
	float AimDistance;
	float Production;
	bool Lobby;
	bool Lee;
	bool Lbox;
 	float Skill;
	float Skill1;
	float Skill3;
	float Skill4;
	float Skill2;
    float Recc;
	EEsp By;
		EEsp By1;

	float Prid;
	float Pridd;
	float Skeleton;
float Size;
	float RadarX;
	float RadarY;
    float Loot;
bool Antiban;

bool IgnoreKnocked;
bool VisCheck;
bool IgnoreBots;
bool Linee;
bool Radar;
bool Health;
bool Name;
bool Distance;
bool Kmkl;
bool TeamID;
bool Dbox;
bool Weapon;
bool LootBox;
bool Ping;
bool LootI;
bool NoBot;
bool Alert;
bool Air;
bool Warning;
bool Genn;
bool ShowVehicle;
bool VehicleFuel;
bool Ipad;
bool Unlock;
bool Less;
bool Skeletonn;
bool Plane;
bool VehicleHealth;
	
    struct sESPMenu {
        bool Line;
        bool Box;
        bool Health;
        bool Skeleton;
        bool Name;
		bool sfps;
        bool Distance;
        bool TeamID;
        bool Vehicle;
		bool LootBox;
		bool Grenade;
        bool NoBot;
    };

    sESPMenu ESPMenu{0};

    struct sAimMenu {
        bool Enable;
        bool AimBot;
		bool FOV;
		bool RecoilComparison;
		bool Yp;
		bool Yq;
		bool Smooth;
		float Position;
		float Meter;
		float Yps;
		float Recc;
		float Smoothness;
		
        EAimTarget Target;
        EAimTrigger Trigger;
        bool IgnoreKnocked;
        bool IgnoreBot;
		float Cross;
        bool VisCheck;
    };
    sAimMenu SilentAim{0};
    sAimMenu AimBot{0};

    struct sHighRisk {
        bool Shake;
        bool Recoil;
        bool Instant;
		bool Bypass5 = true;
        bool FPSUnlock = true;
        bool TSSBypass = true;
        bool TSSBypass2 = true;
        bool blockspect = true;
        bool HitEffect;
        bool Flash;
        bool Parachute;
    };
    sHighRisk HighRisk{0};
    
    struct sPatches {   
	 	bool magicbullet;
};
sPatches Patches;

    struct sOTHER {
        bool FPS;
        bool HIDEESP;
    };
    sOTHER OTHER{0};

    struct sColorsESP {
		float *Text;
	float *Menucolour;
        float *Line;
        float *Box;
		float *Linebot1;
		float *Line1;
		float *Visline;
		float *Boxbot;
        float *Name;
        float *Distance;
        float *Skeleton;
		 float *Skeletonbot;
         float *Skeletonnon;
         float *BotNn;
         float *BotNv;
         float *PotNn;
         float *PotNv;
		 	float *PVLine;
        float *PVILine;
        float *BVLine;
        float *BVILine;
        float *PVBox;
        float *PVIBox;
        float *BVBox;
        float *BVIBox;
		float *Color;
        float *PVSkeleton;
        float *PVISkeleton;
        float *BVSkeleton;
        float *BVISkeleton;
		float *TeamID;
         
		 float *nonbot;
       //  float *Radar;
		  float *Linebot;
        float *Count;
        float *Vehicle;
		float *Fov;
		
    };
    sColorsESP ColorsESP{0};
};
sConfig Config{0};

static bool Feu;

#define CREATE_COLOR(r, g, b, a) new float[4] {(float)r, (float)g, (float)b, (float)a};

// ======================================================================== //

android_app *g_App = 0;
ASTExtraPlayerCharacter *g_LocalPlayer = 0;
ASTExtraPlayerController *g_LocalController = 0;

int currentLang = 0;
#define SelectLanguage(ch, en) currentLang == 0 ? (ch) : (en)
#include "Snowflake.hpp"
#define SNOW_LIMIT 300



#define GNames_Offset 0x4AE0120
#define GUObject_Offset 0xA1C35D8
#define GetActorArray 0x6AD2478
#define GNativeAndroidApp_Offset 0x9FF16D0
#define Actors_Offset 0x70






bool isInsideFOV(int x, int y) {
    if (!Config.AimBot.FOV)
        return true;
    int circle_x = screenWidth / 3.0f;
    int circle_y = screenHeight / 3.0f;
    int rad = Config.AimBot.Cross;
    return (x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad;
}

bool isInsideFOVs(int x, int y) {
    if (!Config.AimBot.Cross)
        return true;

    int circle_x = glWidth / 2;
    int circle_y = glHeight / 2;
    int rad = Config.AimBot.Cross*1.0f;
    return (x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad;
}




struct sRegion {
    uintptr_t start, end;
};

std::vector<sRegion> trapRegions;

bool isObjectInvalid(UObject *obj) {
    if (!Tools::IsPtrValid(obj)) {
        return true;
    }

    if (!Tools::IsPtrValid(obj->ClassPrivate)) {
        return true;
    }

    if (obj->InternalIndex <= 0) {
        return true;
    }

    if (obj->NamePrivate.ComparisonIndex <= 0) {
        return true;
    }

    if ((uintptr_t)(obj) % sizeof(uintptr_t) != 0x0 && (uintptr_t)(obj) % sizeof(uintptr_t) != 0x4) {
        return true;
    }

    if (std::any_of(trapRegions.begin(), trapRegions.end(), [obj](sRegion region) { return ((uintptr_t) obj) >= region.start && ((uintptr_t) obj) <= region.end; }) ||
        std::any_of(trapRegions.begin(), trapRegions.end(), [obj](sRegion region) { return ((uintptr_t) obj->ClassPrivate) >= region.start && ((uintptr_t) obj->ClassPrivate) <= region.end; })) {
        return true;
    }

    return false;
}



static UEngine *GEngine = 0;
UWorld *GetWorld() {
    while (!GEngine) {
        GEngine = UObject::FindObject<UEngine>("UAEGameEngine Transient.UAEGameEngine_1"); // Auto 
        sleep(1);
    }
    if (GEngine) {
        auto ViewPort = GEngine->GameViewport;

        if (ViewPort) {
   //return {};
            return ViewPort->World;
        }
    }
    return 0;
}
TNameEntryArray *GetGNames()
{
	return ((TNameEntryArray * (*)())(UE4 + GNames_Offset))();
}

std::vector<AActor *> getActors()
{
	auto World = GetWorld();
	if (!World)
		return std::vector<AActor *>();

	auto PersistentLevel = World->PersistentLevel;
	if (!PersistentLevel)
		return std::vector<AActor *>();

	auto Actors = *(TArray<AActor *> *)((uintptr_t)PersistentLevel + Actors_Offset);

	std::vector<AActor *> actors;
	for (int i = 0; i < Actors.Num(); i++)
	{
		auto Actor = Actors[i];
		if (Actor)
		{
			actors.push_back(Actor);
		}
	}
	return actors;
}

/*bool UObject::IsA(UClass *cmp) const {
    for (auto super = ClassPrivate; !isObjectInvalid(super); super = static_cast<UClass *>(super->SuperStruct)) {
        if (super == cmp) {
            return true;
        }
    }

    return false;
}*/
// ======================================================================== //
std::string getObjectPath(UObject *Object) {
    std::string s;
    for (auto super = Object->ClassPrivate; super; super = (UClass *) super->SuperStruct) {
        if (!s.empty())
            s += ".";
        s += super->NamePrivate.GetName();
    }
    return s;
}

// ======================================================================== //
int32_t ToColor(float *col) {
    return ImGui::ColorConvertFloat4ToU32(*(ImVec4 *) (col));
}
//==//
FRotator ToRotator(FVector local, FVector target) {
    FVector rotation = UKismetMathLibrary::Subtract_VectorVector(local, target);
    float hyp = sqrt(rotation.X * rotation.X + rotation.Y * rotation.Y);
    FRotator newViewAngle = {0};
    newViewAngle.Pitch = -atan(rotation.Z / hyp) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Yaw = atan(rotation.Y / rotation.X) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Roll = (float) 0.f;
    if (rotation.X >= 0.f)
        newViewAngle.Yaw += 180.0f;
    return newViewAngle;
}

                    auto protect(uintptr_t addr, size_t len, int32_t prot) {
     static_assert(PAGE_SIZE == 4096);
     constexpr size_t page_size =                static_cast<size_t>(PAGE_SIZE);
    void* start = reinterpret_cast<void*>(addr & -page_size);
    uintptr_t end = (addr + len + page_size - 1) & -page_size;
    return mprotect(start, end - reinterpret_cast<uintptr_t>(start), prot);
}

#define W2S(w, s) UGameplayStatics::ProjectWorldToScreen(localController, w, true, s)

/*bool isInsideFOVs(int x, int y) {
    if (!自瞄)
        return true;

    int circle_x = glWidth / 2;
    int circle_y = glHeight / 2;
    int rad = FOV;
    return (x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad;
}*/







auto GetTargetForAimBot() {
    ASTExtraPlayerCharacter *result = 0;
    float max = std::numeric_limits<float>::infinity();

    auto Actors = getActors();
    auto localPlayer = g_LocalPlayer;
    auto localController = g_LocalController;

    if (localPlayer) {
        for (auto Actor : Actors) {
            if (isObjectInvalid(Actor))
                continue;

            if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                auto Player = (ASTExtraPlayerCharacter *) Actor;
				auto Target = (ASTExtraPlayerCharacter *) Actor;

                float dist = localPlayer->GetDistanceTo(Target) / 100.0f;    
                if (dist > Config.AimBot.Meter)
                    continue;

                if (Player->PlayerKey == localPlayer->PlayerKey)
                    continue;

                if (Player->TeamID == localPlayer->TeamID)
                    continue;

                if (Player->bDead)
                    continue;

                if (Config.AimBot.IgnoreKnocked) {
                    if (Player->Health == 0.0f)
                        continue;
                }

                if (Config.AimBot.VisCheck) {
                    if (!localController->LineOfSightTo(Player, {0, 0, 0}, true))
                        continue;
                }

                if (Config.AimBot.IgnoreBot) {
                    if (Player->bIsAI)
                        continue;
                }

                auto Root = Player->GetBonePos("Root", {});
                auto Head = Player->GetBonePos("Head", {});

                FVector2D RootSc, HeadSc;
                if (W2S(Root, &RootSc) && W2S(Head, &HeadSc)) {
                    float height = abs(HeadSc.Y - RootSc.Y);
                    float width = height * 0.65f;

                    FVector middlePoint = {HeadSc.X + (width / 2), HeadSc.Y + (height / 2), 0};
                    if ((middlePoint.X >= 0 && middlePoint.X <= glWidth) && (middlePoint.Y >= 0 && middlePoint.Y <= glHeight)) {
                        FVector2D v2Middle = FVector2D((float) (glWidth / 2), (float) (glHeight / 2));
                        FVector2D v2Loc = FVector2D(middlePoint.X, middlePoint.Y);

                        if (isInsideFOV((int) middlePoint.X, (int) middlePoint.Y)) {

                        float dist = FVector2D::Distance(v2Middle, v2Loc);

                        if (dist < max) {
                            max = dist;
                            result = Player;
                        }
                    }
                }
            }
        }
    }
}
    return result;
}

auto GetTargetByCrossDist() {
	ASTExtraPlayerCharacter *result = 0;
	float max = std::numeric_limits<float>::infinity();

	auto Actors = getActors();

	auto localPlayer = g_LocalPlayer;
	auto localController = g_LocalController;

	if (localPlayer) {
		for (int i = 0; i < Actors.size(); i++) {
			auto Actor = Actors[i];
			if (isObjectInvalid(Actor))
				continue;

			if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass()))	{
				auto Player = (ASTExtraPlayerCharacter *)Actor;
				auto Target = (ASTExtraPlayerCharacter *) Actor;
                float dist = localPlayer->GetDistanceTo(Target) / 100.0f;    
                if (dist > Config.SilentAim.Meter)
                    continue;   
				if (Player->PlayerKey == localPlayer->PlayerKey)
					continue;
				if (Player->TeamID == localPlayer->TeamID)
					continue;
				if (Player->bDead)
					continue;
				if (Config.SilentAim.IgnoreKnocked) {
					if (Player->Health == 0.0f)
						continue;
				}
				if (Config.SilentAim.VisCheck)	{
					if (!localController->LineOfSightTo(Player, {0, 0, 0}, true))
						continue;
				}
				if (Config.SilentAim.IgnoreBot) {
					if (Player->bIsAI)
						continue;
				}
				auto Root = Player->GetBonePos("Root", {});
				auto Head = Player->GetBonePos("Head", {});
				FVector2D RootSc, HeadSc;
				if (W2S(Root, &RootSc) && W2S(Head, &HeadSc)) {
					float height = abs(HeadSc.Y - RootSc.Y);
					float width = height * 0.65f;
					FVector middlePoint = {HeadSc.X + (width / 2), HeadSc.Y + (height / 2), 0};
					if ((middlePoint.X >= 0 && middlePoint.X <= glWidth) && (middlePoint.Y >= 0 && middlePoint.Y <= glHeight)) {
						FVector2D v2Middle = FVector2D((float)(glWidth / 2), (float)(glHeight / 2));
						FVector2D v2Loc = FVector2D(middlePoint.X, middlePoint.Y);
						
						if (isInsideFOV((int) middlePoint.X, (int) middlePoint.Y)) {
                        float dist = FVector2D::Distance(v2Middle, v2Loc);
                        if (dist < max) {
                        max = dist;
                        result = Player;
                            }
                        }
					}
				}
			}
		}
	}
	return result;
}
// ======================================================================== //

const char *GetVehicleName(ASTExtraVehicleBase *Vehicle) {
    switch (Vehicle->VehicleShapeType) {
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Motorbike:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Motorbike_SideCart:
            return "Motorbike";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Dacia:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyDacia:
            return "Dacia";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_MiniBus:
            return "Mini Bus";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PickUp:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PickUp01:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyPickup:
            return "Pick Up";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Buggy:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyBuggy:
            return "Buggy";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ01:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ02:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ03:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyUAZ:
            return "UAZ";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PG117:
            return "PG117";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Aquarail:
            return "Aquarail";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Mirado:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Mirado01:
            return "Mirado";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Rony:
            return "Rony";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Scooter:
            return "Scooter";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_SnowMobile:
            return "Snow Mobile";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_TukTukTuk:
            return "Tuk Tuk";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_SnowBike:
            return "Snow Bike";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Surfboard:
            return "Surf Board";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Snowboard:
            return "Snow Board";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Amphibious:
            return "Amphibious";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_LadaNiva:
            return "Lada Niva";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAV:
            return "UAV";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_MegaDrop:
            return "Mega Drop";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Lamborghini:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Lamborghini01:
            return "Lamborghini";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_GoldMirado:
            return "Gold Mirado";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_BigFoot:
            return "Big Foot";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyUH60:
            return "UH60";
            break;
        default:
            return "Vehicle";
            break;
    }
    return "Vehicle";
}

void (*orig_shoot_event)(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, void *unk1, int unk2) = 0;

void shoot_event(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, ASTExtraShootWeapon *weapon, int unk1) {
    //=================///

            /* if (Config.BulletTracking.Enable) {
   //     ASTExtraPlayerCharacter *Target = GetTargetForBT();
        if (Target) {
            bool triggerOk = false;
            if (Config.BulletTracking.Trigger != EAimTrigger::None) {
                if (Config.BulletTracking.Trigger == EAimTrigger::Shooting) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring;
                } else if (Config.BulletTracking.Trigger == EAimTrigger::Scoping) {
                    triggerOk = g_LocalPlayer->bIsGunADS;
                } else if (Config.BulletTracking.Trigger == EAimTrigger::Both) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring && g_LocalPlayer->bIsGunADS;
                } else if (Config.BulletTracking.Trigger == EAimTrigger::Any) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring || g_LocalPlayer->bIsGunADS;
                }
            } else triggerOk = true;
            if (triggerOk) {
                FVector targetAimPos = Target->GetBonePos("Head", {});
                if (Config.BulletTracking.Target == EAimTarget::Chest) {
                    targetAimPos.Z -= 25.0f;
                }

                UShootWeaponEntity *ShootWeaponEntityComponent = thiz->ShootWeaponEntityComponent;

				
			
                if (ShootWeaponEntityComponent) {
                    ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
                    if (CurrentVehicle) {
                        FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;

      //                  float dist = g_LocalPlayer->GetDistanceTo(Target);
                        auto timeToTravel = dist / ShootWeaponEntityComponent->BulletRange;

                        targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(LinearVelocity, timeToTravel));
                    } else {
       //                 FVector Velocity = Target->GetVelocity();

              //          float dist = g_LocalPlayer->GetDistanceTo(Target);
                        auto timeToTravel = dist / ShootWeaponEntityComponent->BulletRange;

                        targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(Velocity, timeToTravel));
                    }
                    rot = ToRotator(g_LocalController->PlayerCameraManager->CameraCache.POV.Location, targetAimPos);
                }
            }
        }
    }

    return orig_shoot_event(thiz, start, rot, weapon, unk1);*/
}

//=====Bullettradck=====//
class FPSCounter {
protected:
    unsigned int m_fps;
    unsigned int m_fpscount;
    long m_fpsinterval;

public:
    FPSCounter() : m_fps(0), m_fpscount(0), m_fpsinterval(0) {
    }

    void update() {
        m_fpscount++;

        if (m_fpsinterval < time(0)) {
            m_fps = m_fpscount;

            m_fpscount = 0;
            m_fpsinterval = time(0) + 1;
        }
    }

    unsigned int get() const {
        return m_fps;
    }
};

FPSCounter fps;

void DrawBoxEnemy(ImDrawList *draw, ImVec2 X, ImVec2 Y, float thicc, int color) {
    draw->AddLine({X.x, X.y}, {Y.x, Y.y}, color, thicc);
}
//=============================================================================================================
void Line(ImDrawList *draw,FVector2D origin, FVector2D dest, ImColor color)
{
   draw->AddLine({origin.X, origin.Y},{dest.X, dest.Y},color, 1.0f);
}
bool W2S2(FVector worldPos, FVector2D *screenPos) {
    return g_LocalController->ProjectWorldLocationToScreen(worldPos, true, screenPos);
}


void Box3D(ImDrawList *draw, FVector origin, FVector extends, ImColor col) {
    origin.X -= extends.X / 2.f;
    origin.Y -= extends.Y / 2.f;
    origin.Z -= extends.Z / 2.f;
    //никли соси пенис пвнврвнвнв
    
 FVector one = origin;
 FVector two = origin; two.X += extends.X;
 FVector tree = origin; tree.X += extends.X; tree.Y += extends.Y;
 FVector four = origin; four.Y += extends.Y;

 FVector five = one; five.Z += extends.Z;
 FVector six = two; six.Z += extends.Z;
 FVector seven = tree; seven.Z += extends.Z;
 FVector eight = four; eight.Z += extends.Z;

    FVector2D s1, s2, s3, s4, s5, s6, s7, s8;
    if (W2S2(one, &s1) && W2S2(two, &s2) && W2S2(tree, &s3) && W2S2(four, &s4) &&
    W2S2(five, &s5) && W2S2(six, &s6) && W2S2(seven, &s7) && W2S2(eight, &s8))
    {
        
    Line(draw,s1, s2, col);
    Line(draw,s2, s3, col);
    Line(draw,s3, s4, col);
    Line(draw,s4, s1, col);
 
    Line(draw,s5, s6, col);
    Line(draw,s6, s7, col);
    Line(draw,s7, s8, col);
    Line(draw,s8, s5, col);
 
    Line(draw,s1, s5, col);
    Line(draw,s2, s6, col);
    Line(draw,s3, s7, col);
    Line(draw,s4, s8, col);

}
}

void Box4Line(ImDrawList *draw, float thicc, int x, int y, int w, int h, int color) {
    int iw = w / 4;
    int ih = h / 4;
    // top
    draw->AddRect(ImVec2(x, y),ImVec2(x + iw, y), color, thicc);
    draw->AddRect(ImVec2(x + w - iw, y),ImVec2(x + w, y), color, thicc);
    draw->AddRect(ImVec2(x, y),ImVec2(x, y + ih), color, thicc);
    draw->AddRect(ImVec2(x + w - 1, y),ImVec2(x + w - 1, y + ih), color, thicc);;
    // bottom
    draw->AddRect(ImVec2(x, y + h),ImVec2(x + iw, y + h), color, thicc);
    draw->AddRect(ImVec2(x + w - iw, y + h),ImVec2(x + w, y + h), color, thicc);
    draw->AddRect(ImVec2(x, y + h - ih), ImVec2(x, y + h), color, thicc);
    draw->AddRect(ImVec2(x + w - 1, y + h - ih), ImVec2(x + w - 1, y + h), color, thicc);
}
int isOutsideSafezone(FVector2D pos, FVector2D screen) {
    FVector2D mSafezoneTopLeft(screen.X * 0.04f, screen.Y * 0.04f);
    FVector2D mSafezoneBottomRight(screen.X * 0.96f, screen.Y * 0.96f);
    int result = 0;
    if (pos.Y < mSafezoneTopLeft.Y) {
        result |= 1;
    }
    if (pos.X > mSafezoneBottomRight.X) {
        result |= 2;
    }
    if (pos.Y > mSafezoneBottomRight.Y) {
        result |= 4;
    }
    if (pos.X < mSafezoneTopLeft.X) {
        result |= 8;
    }
    return result;
}
FVector2D pushToScreenBorder(FVector2D Pos, FVector2D screen, int borders, int offset) {
    int x = (int)Pos.X;
    int y = (int)Pos.Y;
    if ((borders & 1) == 1) {
        y = 0 - offset;
    }
    if ((borders & 2) == 2) {
        x = (int)screen.X + offset;
    }
    if ((borders & 4) == 4) {
        y = (int)screen.Y + offset;
    }
    if ((borders & 8) == 8) {
        x = 0 - offset;
    }
    return FVector2D(x, y);
}

FRotator ClampAngles(FRotator inRot) {
    FRotator outRot = inRot;
    if (outRot.Pitch > 180)
        outRot.Pitch -= 360;
    if (outRot.Pitch < -180)
        outRot.Pitch += 360;

    if (outRot.Pitch < -75.f)
        outRot.Pitch = -75.f;
    else if (outRot.Pitch > 75.f)
        outRot.Pitch = 75.f;

    while (outRot.Yaw < -180.0f)
        outRot.Yaw += 360.0f;
    while (outRot.Yaw > 180.0f)
        outRot.Yaw -= 360.0f;
    return outRot;
}


//===================== ESP DRAW =====================//
void DrawESP(ImDrawList *draw) {

if (Config.Bypass) {
MemoryPatch::createWithHex("libanogs.so",0x38C990,"00 20 70 47").Modify();//3000
MemoryPatch::createWithHex("libanogs.so",0xFDAEC,"00 20 70 47").Modify();//3000
MemoryPatch::createWithHex("libanogs.so",0x3672CC,"00 20 70 47").Modify();//4700
MemoryPatch::createWithHex("libanogs.so",0x38FABC,"00 20 70 47").Modify();//3000
MemoryPatch::createWithHex("libanogs.so",0x110888,"00 20 70 47").Modify();//4000
MemoryPatch::createWithHex("libanogs.so",0x36699A,"00 20 70 47").Modify();//6600
MemoryPatch::createWithHex("libanogs.so",0x35DEAC,"00 20 70 47").Modify();//3000
MemoryPatch::createWithHex("libanogs.so",0x35B2AC,"00 20 70 47").Modify();//5000
MemoryPatch::createWithHex("libanogs.so",0x390F38,"00 20 70 47").Modify();//3900
MemoryPatch::createWithHex("libanogs.so",0x366926,"00 20 70 47").Modify();//4000
MemoryPatch::createWithHex("libanogs.so",0x366ADA,"00 20 70 47").Modify();//3000
}

draw->AddText(NULL, ((float) density / 15.0f),{(float) glWidth / 13 + glWidth / 30,15},IM_COL32(0, 255, 255, 255),(OBFUSCATE("Feedbacks: @S8_q1")));
draw->AddText(NULL, ((float) density / 15.0f),{(float) glWidth / 2 + glWidth / 5,14},IM_COL32(0, 255, 255, 255),(OBFUSCATE("Expiry:  ")));
draw->AddText(NULL, ((float) density / 15.0f),{(float) glWidth / 2 + glWidth / 4,16},IM_COL32(0, 255, 255, 255),EXP.c_str());
draw->AddText(NULL, ((float) density / 15.0f),{(float) glWidth / 150 + glWidth / 40,650},IM_COL32(0, 255, 255, 255),(OBFUSCATE("Ue4 - Anogs 7769")));
			
											
			
	
draw->AddText(NULL, ((float) density / 10.0f),{(float) glWidth / 25 + glWidth / 125,150},IM_COL32(255, 255, 255, 255),
                          "                                   ZoloCheat-Safe"); 
                          
if (Config.HighRisk.TSSBypass) {
                auto objs = UObject::GetGlobalObjects();
        for (int i = 0; i < objs.Num(); i++) {
            auto Object = objs.GetByIndex(i);
   if (isObjectInvalid(Object))
                continue;
			   
			     			   if (Config.HighRisk.Bypass5) {
					 auto objs = UObject::GetGlobalObjects();
        for (int i = 0; i < objs.Num(); i++) {
            auto Object = objs.GetByIndex(i);
   if (isObjectInvalid(Object))
                continue;

                 if (Object->IsA(UGameFrontendHUD::StaticClass())) {
                 auto SDK_UGameFrontendHUD = (UGameFrontendHUD *) Object;
                 
                 
                 
                 SDK_UGameFrontendHUD->bUseDolphinUpdateFirst = 0;
                 SDK_UGameFrontendHUD->bEnableUseDolphinUpdate = 0;
                 SDK_UGameFrontendHUD->bEnableUseCDNUpdate = 0;
                 SDK_UGameFrontendHUD->bUseDolphinUpdateAfterCDNFailed = 0;
                 SDK_UGameFrontendHUD->bUseCDNUpdateAfterDolphinFailed = 0;
                 SDK_UGameFrontendHUD->bEnableEditorPufferDownload = 0;
                 
                 SDK_UGameFrontendHUD->bIsWaitingUpdateStateData = 0;
                 SDK_UGameFrontendHUD->EnableTickLog = 0;
                 
                 
                 
            }     
                 
                 //bEnableTssSdkAntiDataFilter
                 
                 
                 
                 
              }   
               }

         
             if (Config.HighRisk.Bypass5) {
                 if (Object->IsA(UGameFrontendHUD::StaticClass())) {
                 auto SDK_UGameFrontendHUD = (UGameFrontendHUD *) Object;
                
                 SDK_UGameFrontendHUD->EnableTickLog = 0;
                     
             //    SDK_UGameFrontendHUD->DisableGVoice = 1;
                     
                 SDK_UGameFrontendHUD->bUseDolphinUpdateFirst = 0;
                 SDK_UGameFrontendHUD->bEnableUseDolphinUpdate = 0;
                 SDK_UGameFrontendHUD->bEnableUseCDNUpdate = 0;
                 SDK_UGameFrontendHUD->bUseDolphinUpdateAfterCDNFailed = 0;
                 SDK_UGameFrontendHUD->bUseCDNUpdateAfterDolphinFailed = 0;
           //      SDK_UGameFrontendHUD->bUseCDNUpdateAfterDolphinFailed = 0;
                 SDK_UGameFrontendHUD->bEnableEditorPufferDownload = 0;
                 
                 SDK_UGameFrontendHUD->bIsWaitingUpdateStateData = 0;
                 SDK_UGameFrontendHUD->IsUsingDolphinUpdate = 0;
                 SDK_UGameFrontendHUD->IsUsingCDNUpdate = 0;
        
                 SDK_UGameFrontendHUD->ODPaksEnable = 0;
                 SDK_UGameFrontendHUD->bUseDynamicCreateLuaManager = 0;
                 SDK_UGameFrontendHUD->bPatchReInitSequence = 0;
                 SDK_UGameFrontendHUD->bCallLuaTick = 0;     
                 SDK_UGameFrontendHUD->bAutoLoginEnable = 1;     
                      
                      
                 SDK_UGameFrontendHUD->bUnLoadNoGcPackage = 0;
                 SDK_UGameFrontendHUD->bFlushAsyncLoadingBeforeGC = 0;
               //  SDK_UGameFrontendHUD->bEnablePandora = 0;     
                 SDK_UGameFrontendHUD->bEnableJMLog = 0;     
                      
                 SDK_UGameFrontendHUD->bEnableH5Cache = 0;
                 SDK_UGameFrontendHUD->bCheckWorldNameForLoadConfig = 0;     
                 SDK_UGameFrontendHUD->IsNativeHUDTickLock = 0;     
                      
                 
                 SDK_UGameFrontendHUD->IsShutDown = 0;

                    if (Object->IsA(UGDolphinUpdater::StaticClass())) {
                auto SDK_UGDolphinUpdater = (UGDolphinUpdater *) Object;
                 
                 
                 
                 
                 SDK_UGDolphinUpdater->AllowIOSBGDownload = 0;
                 SDK_UGDolphinUpdater->AllowIOSBGDownloadPush = 0;     
                 SDK_UGDolphinUpdater->DisableJPKRBGDownloadNightPush = 1;     
                 SDK_UGDolphinUpdater->EnableRandomBackupURL = 0;
                 SDK_UGDolphinUpdater->EnablePufferUpdate = 0;     
                 SDK_UGDolphinUpdater->OpenDebugLog = 0;     
                 
                 
                 
                 }
                 
                 
                 
                     
                 
                 
                 
                 
               }
               
               
               
               if (Object->IsA(UBulletHitInfoUploadComponent::StaticClass())) {
                 auto SDK_UBulletHitInfoUploadComponent = (UBulletHitInfoUploadComponent *) Object;
    //thirdparty ban
                 SDK_UBulletHitInfoUploadComponent->bEnableTssSdkAntiData = 0;
                 SDK_UBulletHitInfoUploadComponent->bEnableTssSdkAntiDataFilter = 0;
                 SDK_UBulletHitInfoUploadComponent->bEnableTssSdkAntiDataFilterNew = 0;
                 SDK_UBulletHitInfoUploadComponent->bDisableDsTick = 1;
                 SDK_UBulletHitInfoUploadComponent->bDisableDsAntiDataReport = 1;
                 SDK_UBulletHitInfoUploadComponent->bEnableAddSPCShootData = 0;
                 SDK_UBulletHitInfoUploadComponent->NeedSendSimpleCharacterHitData = 0;
               
               
               
               }
               
               
               if (Object->IsA(ASTExtraBaseCharacter::StaticClass())) {
                 auto SDK_ASTExtraBaseCharacter = (ASTExtraBaseCharacter *) Object;
    
                 SDK_ASTExtraBaseCharacter->IsEnableReportPlayerBehavior = 0;
            //   SDK_ASTExtraBaseCharacter->UseShootVerifyEx = 0;
               SDK_ASTExtraBaseCharacter->bIsDelayingMove = 0;
               SDK_ASTExtraBaseCharacter->bDebugNewWeaponSystem = 0;
               
                 SDK_ASTExtraBaseCharacter->bDebugPVEShoot = 0;
               
                 SDK_ASTExtraBaseCharacter->bRecordKillData = 0;
               
                 
               SDK_ASTExtraBaseCharacter->bEnableRagdollAfterDead = 1;
               SDK_ASTExtraBaseCharacter->EnableSprintSync = 0;
               SDK_ASTExtraBaseCharacter->IsPveShootVerify = 0;
               SDK_ASTExtraBaseCharacter->IsOpenCommonShootVerify = 0;
               SDK_ASTExtraBaseCharacter->bDetectingPaintDecalTarget = 0;
               
               
               
               SDK_ASTExtraBaseCharacter->bDetectingPaintDecalTarget = 0;
               SDK_ASTExtraBaseCharacter->bValidPaintDecalTarget = 0;
               SDK_ASTExtraBaseCharacter->IsEnableReportRoute = 0;
               SDK_ASTExtraBaseCharacter->IsEnableReportPlayerKillFlow = 0;
               SDK_ASTExtraBaseCharacter->IsEnableReportGameSetting = 0;
               SDK_ASTExtraBaseCharacter->IsEnableReportMrpcsFlow = 0;
               SDK_ASTExtraBaseCharacter->IsEnableReportMrpcsInPartCircleFlow = 0;
               SDK_ASTExtraBaseCharacter->IsEnableReportMrpcsInCircleFlow = 0;
               
               
               }
			   
			   
			   
			   
			   
			   
         }
         
    if (Config.HighRisk.Bypass5) {
		auto Actors = getActors();
        for (int i = 0; i < Actors.size(); i++) {
            auto Actor = Actors[i];
            if (isObjectInvalid(Actor))
                continue;

            if (Actor->IsA(ASTExtraPlayerController::StaticClass())) {
                auto SDK_ASTExtraPlayerCharacter = (ASTExtraPlayerController *) Actor;
				
				
				SDK_ASTExtraPlayerCharacter->bShouldReportAntiCheat = 0;
				SDK_ASTExtraPlayerCharacter->bUseAntiDataReportFilter = 0;
				SDK_ASTExtraPlayerCharacter->bUseAntiDataReportFilterNew = 0;
				SDK_ASTExtraPlayerCharacter->bUseAntiDataReportFilterCheck = 0;
				SDK_ASTExtraPlayerCharacter->LastReportAntiDataTime = 0;
				SDK_ASTExtraPlayerCharacter->bEnableDSErrorLogReport = 0;

				//bool 
				
				
				
				} 
				}
				}
				
				
         
           /*   if (Config.HighRisk.Bypass5) {
                 if (Object->IsA(UTssManager::StaticClass())) {
                 auto SDK_UTssManager = (UTssManager *) Object;
                 
                 SDK_UTssManager->TssCDNHostInfo = FString(L"testing");
                 SDK_UTssManager->TssHostInfo = FString(L"testing");
                 SDK_UTssManager->TssCDNHostInfo = FString(L"testing");
                 SDK_UTssManager->TssBuildInIpInfo = FString(L"testing");
                 
                 SDK_UTssManager->TssLocal = int(L"testing");
               }
         }*/
        
        
        
        
        }
              
          
    }



        auto Actors = getActors();

        int totalEnemies = 0, totalBots = 0;

        ASTExtraPlayerCharacter *localPlayer = 0;
        ASTExtraPlayerController *localController = 0;
		
        std::string sFPS = "FPS: ";
        sFPS += std::to_string(fps.get());


		/*if (Config.HighRisk.Recoil) {
            draw->AddText({((float) density / 10.0f), 40}, IM_COL32(0, 255, 0, 255),
                          "\nLess Recoil Safe (On)");
			}else{
		draw->AddText({((float) density / 10.0f), 40}, IM_COL32(255, 0, 0, 255),
                          "\nLess Recoil Safe (Off)");
        }*/
   //     draw->AddText({((float) density / 50.0f), 50}, IM_COL32(0,255,0, 250),"   WANT KEY DM - @surprise_owner \n FULL SAFE VIP MOD \n WANNA YOUR OWM MOD DM - \n  @surprise_owner");     

 //  draw->AddText({((float) density / 50.0f), 50}, IM_COL32(0,255,0, 250),floating.c_str());

  draw->AddText({ ((float) density / 200.0f), 570},IM_COL32(0,255,0, 250),"");
  draw->AddText({ ((float) density / 200.0f), 600},IM_COL32(0,255,0, 250),"");
//  draw->AddText({ ((float) density / 200.0f), 630},IM_COL32(0,255,0, 250),status.c_str());

        
        
        for (int i = 0; i < Actors.size(); i++) {
            auto Actor = Actors[i];
            if (isObjectInvalid(Actor))
                continue;

				 if (localController ==0){
        std::string sFPS = "";
        draw->AddText({((float) density / 10.0f), 40},IM_COL32(255, 0, 0, 255),sFPS.c_str());
    }else{
            }

				
				
            if (Actor->IsA(ASTExtraPlayerController::StaticClass())) {
                localController = (ASTExtraPlayerController *) Actor;
                break;
            }
        }

        if (localController) {
            for (int i = 0; i < Actors.size(); i++) {
                auto Actor = Actors[i];
                if (isObjectInvalid(Actor))
                    continue;

                if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                    if (((ASTExtraPlayerCharacter *) Actor)->PlayerKey ==
                        localController->PlayerKey) {
                        localPlayer = (ASTExtraPlayerCharacter *) Actor;
                        break;
                    }
                }
            }


            if (localPlayer) {
                if (localPlayer->PartHitComponent) {
                    auto ConfigCollisionDistSqAngles = localPlayer->PartHitComponent->ConfigCollisionDistSqAngles;
                    for (int j = 0; j < ConfigCollisionDistSqAngles.Num(); j++) {
                        ConfigCollisionDistSqAngles[j].Angle = 90.0f;
                    }
                    localPlayer->PartHitComponent->ConfigCollisionDistSqAngles = ConfigCollisionDistSqAngles;
                }

              
				
				
				
				
				
				
				
				
				
				
				
                //Aimbot//
				  if (Config.AimBot.Enable) {
                      
                if (Config.AimBot.Target == EAimTarget::Auto){
                   
                static bool THead,TNeck,TSpaine01,TSpaine02,TSpaine03,TPlesive,TLuparm,TLlowarm,TLhand,TRuparm,TRlowarm,TRhand,TLthigh,TLcalf,TLfoot,TRthigh,TRcalf,TRfoot;
                static bool AlreadyChoose = false;
				
                ASTExtraPlayerCharacter *Target = GetTargetByCrossDist();
				
                if(Target){
                    if(!g_LocalController->LineOfSightTo(g_LocalController->PlayerCameraManager,Target->GetBonePos("neck_01", {}), true)){
                TRuparm = false; //Controller Can't See TagertPosition
                }else{
                TRuparm = true; // Controller Can See TargetPosition
                }
                
                if(!g_LocalController->LineOfSightTo(g_LocalController->PlayerCameraManager,Target->GetBonePos("upperarm_l", {}), true)){
                TLuparm = false; //Controller Can't See TagertPosition
                }else{
                TLuparm = true; // Controller Can See TargetPosition
                }
                
                if(!g_LocalController->LineOfSightTo(g_LocalController->PlayerCameraManager,Target->GetBonePos("lowerarm_r", {}), true)){
                TRlowarm = false; //Controller Can't See TagertPosition
                }else{
                TRlowarm = true; // Controller Can See TargetPosition
                }
                
                if(!g_LocalController->LineOfSightTo(g_LocalController->PlayerCameraManager,Target->GetBonePos("lowerarm_l", {}), true)){
                TLlowarm = false; //Controller Can't See TagertPosition
                }else{
                TLlowarm = true; // Controller Can See TargetPosition
                }
                
                if(!g_LocalController->LineOfSightTo(g_LocalController->PlayerCameraManager,Target->GetBonePos("hand_r", {}), true)){
                TRhand = false; //Controller Can't See TagertPosition
                }else{
                TRhand = true; // Controller Can See TargetPosition
                }
                
                if(!g_LocalController->LineOfSightTo(g_LocalController->PlayerCameraManager,Target->GetBonePos("hand_l", {}), true)){
                TLhand = false; //Controller Can't See TagertPosition
                }else{
                TLhand = true; // Controller Can See TargetPosition
                }
                
                
                ///
                
                if(!g_LocalController->LineOfSightTo(g_LocalController->PlayerCameraManager,Target->GetBonePos("upperarm_r", {}), true)){
                THead = false; //Controller Can't See TagertPosition
                }else{
                THead = true; // Controller Can See TargetPosition
                }
                
                if(!g_LocalController->LineOfSightTo(g_LocalController->PlayerCameraManager,Target->GetBonePos("upperarm_l", {}), true)){
                TNeck = false; //Controller Can't See TagertPosition
                }else{
                TNeck = true; // Controller Can See TargetPosition
                }
                
                if(!g_LocalController->LineOfSightTo(g_LocalController->PlayerCameraManager,Target->GetBonePos("spine_01", {}), true)){
                TSpaine01 = false; //Controller Can't See TagertPosition
                }else{
                TSpaine01 = true; // Controller Can See TargetPosition
                }
                
                if(!g_LocalController->LineOfSightTo(g_LocalController->PlayerCameraManager,Target->GetBonePos("spine_02", {}), true)){
                TSpaine02 = false; //Controller Can't See TagertPosition
                }else{
                TSpaine02 = true; // Controller Can See TargetPosition
                }
                
                if(!g_LocalController->LineOfSightTo(g_LocalController->PlayerCameraManager,Target->GetBonePos("spine_03", {}), true)){
                TSpaine03 = false; //Controller Can't See TagertPosition
                }else{
                TSpaine03 = true; // Controller Can See TargetPosition
                }
                
                
                
                if(!g_LocalController->LineOfSightTo(g_LocalController->PlayerCameraManager,Target->GetBonePos("pelvis", {}), true)){
                TPlesive = false; //Controller Can't See TagertPosition
                }else{
                TPlesive = true; // Controller Can See TargetPosition
                }
                
                if(!g_LocalController->LineOfSightTo(g_LocalController->PlayerCameraManager,Target->GetBonePos("thigh_r", {}), true)){
                TRthigh = false; //Controller Can't See TagertPosition
                }else{
                TRthigh = true; // Controller Can See TargetPosition
                }
                
                if(!g_LocalController->LineOfSightTo(g_LocalController->PlayerCameraManager,Target->GetBonePos("thigh_l", {}), true)){
                TLthigh = false; //Controller Can't See TagertPosition
                }else{
                TLthigh = true; // Controller Can See TargetPosition
                }
                
                if(!g_LocalController->LineOfSightTo(g_LocalController->PlayerCameraManager,Target->GetBonePos("calf_r", {}), true)){
                TRcalf = false; //Controller Can't See TagertPosition
                }else{
                TRcalf = true; // Controller Can See TargetPosition
                }
                
                if(!g_LocalController->LineOfSightTo(g_LocalController->PlayerCameraManager,Target->GetBonePos("calf_l", {}), true)){
                TLcalf = false; //Controller Can't See TagertPosition
                }else{
                TLcalf = true; // Controller Can See TargetPosition
                }
                
                if(!g_LocalController->LineOfSightTo(g_LocalController->PlayerCameraManager,Target->GetBonePos("foot_r", {}), true)){
                TRfoot = false; //Controller Can't See TagertPosition
                }else{
                TRfoot = true; // Controller Can See TargetPosition
                }
                
                if(!g_LocalController->LineOfSightTo(g_LocalController->PlayerCameraManager,Target->GetBonePos("foot_l", {}), true)){
                TLfoot = false; //Controller Can't See TagertPosition
                }else{
                TLfoot = true; // Controller Can See TargetPosition
                }
                
                if(!AlreadyChoose){ //First Attack Postition.For Safety I Choose Neck Not Head.
                if(TNeck){
                AutoTargetChoose = 1; //Neck
                AlreadyChoose = true;
                }else{
                AlreadyChoose = false;
                }
                }              
                
                 if(!AlreadyChoose){ //Second Attack Postition
                if(TSpaine03){
                AutoTargetChoose = 2; 
                AlreadyChoose = true;
                }else{
                AlreadyChoose = false;
                }
                }            
                
                if(!AlreadyChoose){ //Third Attack Postition
                if(TSpaine02){
                AutoTargetChoose = 3; 
                AlreadyChoose = true;
                }else{
                AlreadyChoose = false;
                }
                }            
                
                if(!AlreadyChoose){ //Fourth Attack Postition
                if(TSpaine01){
                AutoTargetChoose = 4; 
                AlreadyChoose = true;
                }else{
                AlreadyChoose = false;
                }
                }
                
                if(!AlreadyChoose){ //Five Attack Postition
                if(TPlesive){
                AutoTargetChoose = 5; 
                AlreadyChoose = true;
                }else{
                AlreadyChoose = false;
                }
                }
                
                if(!AlreadyChoose){ 
                if(TRuparm){
                AutoTargetChoose = 6; 
                AlreadyChoose = true;
                }else{
                AlreadyChoose = false;
                }
                }
                
                if(!AlreadyChoose){ 
                if(TLuparm){
                AutoTargetChoose = 7; 
                AlreadyChoose = true;
                }else{
                AlreadyChoose = false;
                }
                }
                
                if(!AlreadyChoose){ 
                if(TRlowarm){
                AutoTargetChoose = 8; 
                AlreadyChoose = true;
                }else{
                AlreadyChoose = false;
                }
                }
                
                if(!AlreadyChoose){ 
                if(TLlowarm){
                AutoTargetChoose = 9; 
                AlreadyChoose = true;
                }else{
                AlreadyChoose = false;
                }
                }   
                
                if(!AlreadyChoose){ 
                if(TRhand){
                AutoTargetChoose = 10; 
                AlreadyChoose = true;
                }else{
                AlreadyChoose = false;
                }
                }
                
                if(!AlreadyChoose){ 
                if(TLhand){
                AutoTargetChoose = 11; 
                AlreadyChoose = true;
                }else{
                AlreadyChoose = false;
                }
                }
                
                if(!AlreadyChoose){ 
                if(TRthigh){
                AutoTargetChoose = 12; 
                AlreadyChoose = true;
                }else{
                AlreadyChoose = false;
                }
                }
                
                if(!AlreadyChoose){ 
                if(TLthigh){
                AutoTargetChoose = 13; 
                AlreadyChoose = true;
                }else{
                AlreadyChoose = false;
                }
                }
                
                if(!AlreadyChoose){ 
                if(TRcalf){
                AutoTargetChoose = 14; 
                AlreadyChoose = true;
                }else{
                AlreadyChoose = false;
                }
                }
                
                if(!AlreadyChoose){ 
                if(TLcalf){
                AutoTargetChoose = 15; 
                AlreadyChoose = true;
                }else{
                AlreadyChoose = false;
                }
                }
                
                if(!AlreadyChoose){ 
                if(TRfoot){
                AutoTargetChoose = 16; 
                AlreadyChoose = true;
                }else{
                AlreadyChoose = false;
                }
                }
                
                if(!AlreadyChoose){ 
                if(TLfoot){
                AutoTargetChoose = 17; 
                AlreadyChoose = true;
                }else{
                AlreadyChoose = false;
                }
                }
                }
                AlreadyChoose = false; //Return
              }
            }
            
			
				if (Config.AimBot.Enable) {
				
				draw->AddCircle(ImVec2(glWidth / 2.0f, glHeight / 2.0f), Config.AimBot.Cross*0.5f, IM_COL32(255, 0, 0, 255), 100, 1.0f);
           
                				
                long PlayerAimLineColor = ImColor(255,255,255,255);
                   
                    	ASTExtraPlayerCharacter *Target = GetTargetForAimBot();
                    if (Target) {
                        FVector HEAD = Target->GetBonePos("Head", {});
                        
                        ImVec2 HeadPosSC;
                        if (W2S(HEAD, (FVector2D *)&HeadPosSC)) {
                    
                           
                        /*  draw->AddLine({(float) glWidth / 2,  (float) (glHeight / 2)}, HeadPosSC,
                                              PlayerAimLineColor, 1.0f);*/
                            
                        }
                        bool triggerOk = false;
                        if (Config.AimBot.Trigger != EAimTrigger::None) {
                            if (Config.AimBot.Trigger == EAimTrigger::Shooting) {
                                triggerOk = localPlayer->bIsWeaponFiring;
                            } else if (Config.AimBot.Trigger == EAimTrigger::Scoping) {
                                triggerOk = localPlayer->bIsGunADS;
                            } else if (Config.AimBot.Trigger == EAimTrigger::Both) {
                                triggerOk = localPlayer->bIsWeaponFiring && localPlayer->bIsGunADS;
                            } else if (Config.AimBot.Trigger == EAimTrigger::Any) {
                                triggerOk = localPlayer->bIsWeaponFiring || localPlayer->bIsGunADS;
                            }
                        } else triggerOk = true;
						
						
                        if (triggerOk) {
                            FVector targetAimPos = Target->GetBonePos("Head", {});
							
                            if (Config.AimBot.Target == EAimTarget::Chest) {
                                targetAimPos.Z -= 25.0f;
                        }
						
				  if (Config.AimBot.Target == EAimTarget::Auto) {
                           if (AutoTargetChoose == 1) {
                             targetAimPos = Target->GetBonePos("neck_01", {});
                               } else if(AutoTargetChoose == 2){
                             targetAimPos = Target->GetBonePos("spine_03", {});
                               } else if(AutoTargetChoose == 3){
                             targetAimPos = Target->GetBonePos("spine_02", {});
                               } else if(AutoTargetChoose == 4){
                             targetAimPos = Target->GetBonePos("spine_01", {});
                               } else if(AutoTargetChoose == 5){
                             targetAimPos = Target->GetBonePos("foot_l", {});
                               } else if(AutoTargetChoose == 6){
                             targetAimPos = Target->GetBonePos("foot_r", {});
                               } else if(AutoTargetChoose == 7){
                             targetAimPos = Target->GetBonePos("upper_l", {});
                               } else if(AutoTargetChoose == 8){
                             targetAimPos = Target->GetBonePos("lowerarm_r", {});
                               } else if(AutoTargetChoose == 9){
                             targetAimPos = Target->GetBonePos("thigh_l", {});
                               } else if(AutoTargetChoose == 10){
                             targetAimPos = Target->GetBonePos("calf_l", {});
                               } else if(AutoTargetChoose == 11){
                             targetAimPos = Target->GetBonePos("upper_r", {});
                               } else if(AutoTargetChoose == 12){
                             targetAimPos = Target->GetBonePos("lowerarm_r", {});
                               } else if(AutoTargetChoose == 13){
                             targetAimPos = Target->GetBonePos("thigh_r", {});
                               } else if(AutoTargetChoose == 14){
                             targetAimPos = Target->GetBonePos("calf_r", {});
                               }else if(AutoTargetChoose == 15){
                             targetAimPos = Target->GetBonePos("calf_r", {});
                               }else if(AutoTargetChoose == 16){
                             targetAimPos = Target->GetBonePos("calf_r", {});
                               }                               
                            }
			  
                            	auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                            	if (WeaponManagerComponent) {
                                	auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                                	if ((int) propSlot.GetValue() >= 1 && (int) propSlot.GetValue() <= 3) {
                                    	auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
                                    	if (CurrentWeaponReplicated) {
                                        	auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
                                        	if (ShootWeaponComponent) {
                                            	UShootWeaponEntity *ShootWeaponEntityComponent = ShootWeaponComponent->ShootWeaponEntityComponent;
                                    if (ShootWeaponEntityComponent) {
										if(!Config.AimBot.Smooth){
                                        	if (Config.AimBot.Yp) {
                                                		ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
                                                		if (CurrentVehicle) {
                                                    		FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;
                                                    		float dist = localPlayer->GetDistanceTo(Target);
                                                    		auto timeToTravel = dist / ShootWeaponEntityComponent->BulletRange;
                                                    		targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(LinearVelocity, timeToTravel));
                                                    		targetAimPos.Z += LinearVelocity.Z * timeToTravel + Config.Box1 * Config.AimBot.Yps* 10000 * timeToTravel * timeToTravel;
                                                		} else {
                                                    		FVector Velocity = Target->GetVelocity();
                                                    		float dist = localPlayer->GetDistanceTo(Target);
                                                    		auto timeToTravel = dist / ShootWeaponEntityComponent->BulletRange;
                                                    		targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(Velocity, timeToTravel));
                                                    		targetAimPos.Z += Velocity.Z * timeToTravel + Config.Box1 * 10000 * Config.AimBot.Yps * timeToTravel * timeToTravel;
                                                		}
													}
                                                }
                            	if (Config.AimBot.Yq) {
                       if (g_LocalPlayer->bIsGunADS) {
                       if (g_LocalPlayer->bIsWeaponFiring) {
                  float dist = g_LocalPlayer->GetDistanceTo(Target) / 100.f;
          	targetAimPos.Z -= dist * float(Config.AimBot.Recc);
                                                        	}
                                                    	}
                                                	}
                                                	
                                                	
                                                	
                                                                                              if (Config.AimBot.Enable) {
                            if (g_LocalPlayer->bIsGunADS) {
                               if (g_LocalPlayer->bIsWeaponFiring) {
                                float dist = g_LocalPlayer->GetDistanceTo(Target) / 100.f;                                                                                 
                                targetAimPos.Z -= dist * 1.25f;        
                                
                                                          
                                }  
                             }
                           }                	
                                                	
                                                	
                                                	
													FVector localPos = g_LocalPlayer->GetBonePos("Head",{});
                                                	
                                       	  if (Config.AimBot.Enable) {
                                   FRotator m_Rotation = g_LocalController->ControlRotation;                                
                                   auto aimRotation = ToRotator(localPos, targetAimPos);
       
                              if (Config.AimBot.Smooth) {
								  Config.AimBot.Yp = false;
                                   aimRotation.Pitch -= m_Rotation.Pitch;
                                   aimRotation.Yaw -= m_Rotation.Yaw;
 
                                   ClampAngles(aimRotation);
 
                                   m_Rotation.Pitch += aimRotation.Pitch / (float) Config.AimBot.Smoothness;
                                   m_Rotation.Yaw += aimRotation.Yaw / (float) Config.AimBot.Smoothness;
                                } else {
                                   ClampAngles(aimRotation);
                                   m_Rotation.Pitch = aimRotation.Pitch;
                                   m_Rotation.Yaw = aimRotation.Yaw;
                                              }
								   g_LocalController->ControlRotation = m_Rotation;	  
                                           }

  
											  
								
                                                	localController->SetControlRotation(ToRotator(localController->PlayerCameraManager->CameraCache.POV.Location, targetAimPos), "");
                                            	}
                                        	}
                                    	}
                                	}
                            	}
                        	}
                    	}
					}
                
                
                
                
                
        
        if (Config.AimBot.Enable) {
        Config.AimBot.Meter = 50.0f;
        Config.AimBot.VisCheck = true;
        Config.AimBot.Yps = 300.0f;
        Config.AimBot.Smooth = true;
        Config.AimBot.Smoothness = 15.0f;
        Config.AimBot.Yq = true;
        }
        
        
        
        
        
                        
                                        
                                                        
                                                                        
                                                                                                        
               
                
                
                
                
                
                
				
     for (int i = 0; i < Actors.size(); i++) {
                    auto Actor = Actors[i];
                    if (isObjectInvalid(Actor))
                        continue;
                        if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                            long PlayerBoxClrCf = IM_COL32(0, 255, 0, 255);
                            long PlayerBoxClrCf2 = IM_COL32(252, 0, 0, 25);
                            auto Player = (ASTExtraPlayerCharacter *) Actor;
                            if (!localController->LineOfSightTo(Player, {0, 0, 0}, true)) {
                                PlayerBoxClrCf = IM_COL32(255, 0, 0, 255);
                                PlayerBoxClrCf2 = IM_COL32(255, 0, 0, 25);
                            }
                            float Distance = localPlayer->GetDistanceTo(Player) / 100.0f;
                            if (Distance > 500.0f)
                                continue;

                            if (Player->PlayerKey == localController->PlayerKey)
                                continue;

                            if (Player->TeamID == localController->TeamID)
                                continue;

                            if (Player->bDead)
                                continue;

                            if (Player->bIsAI)
                                totalBots++;
                           else totalEnemies++;

                            if (Config.ESPMenu.NoBot)
                            if (Player->bIsAI)
                                continue;

								float magic_number = (Distance);
                    float mx = (glWidth / 4) / magic_number;

                    float healthLength = glWidth / 17;
                    if (healthLength < mx)
                        healthLength = mx;
								
                           /* auto HeadPos = Player->GetBonePos("Head", {});
                            HeadPos.Z = HeadPos.Z + 1.0f; 
                            ImVec2 headPosSC;

                            auto RootPos = Player->GetBonePos("Root", {});
                            ImVec2 RootPosSC;*/
                            
                                                        auto HeadPos = Player->GetBonePos("Head", {});
                             ImVec2 headPosSC;

                             auto RootPos = Player->GetBonePos("Root", {});
                             ImVec2 RootPosSC;

                             FVector Root = Player->GetBonePos("Root", {});
                             FVector Spin = Player->GetBonePos("pelvis", {});
                             FVector Spin2 = Player->GetBonePos("spine_03", {});
                             auto pelvis = Player->GetBonePos("pelvis", {});
                             ImVec2 pelvisPoSC;
                             
                      auto upper_r = Player->GetBonePos("upperarm_r", {});
                      ImVec2 upper_rPoSC;
                      auto lowerarm_r = Player->GetBonePos("lowerarm_r", {});
                      ImVec2 lowerarm_rPoSC;
                      auto hand_r = Player->GetBonePos("hand_r", {});
                      ImVec2 hand_rPoSC;
                      auto upper_l = Player->GetBonePos("upperarm_l", {});
                      ImVec2 upper_lPoSC;
                      auto lowerarm_l = Player->GetBonePos("lowerarm_l", {});
                      ImVec2 lowerarm_lSC;
                      auto hand_l = Player->GetBonePos("hand_l", {});
                      ImVec2 hand_lPoSC;
                      auto thigh_l = Player->GetBonePos("thigh_l", {});
                      ImVec2 thigh_lPoSC;
                      auto calf_l = Player->GetBonePos("calf_l", {});
                      ImVec2 calf_lPoSC;
                      auto foot_l = Player->GetBonePos("foot_l", {});
                      ImVec2 foot_lPoSC;
                         auto thigh_r = Player->GetBonePos("thigh_r", {});
                         ImVec2 thigh_rPoSC;
                         auto calf_r = Player->GetBonePos("calf_r", {});
                         ImVec2 calf_rPoSC;
                                    
                         auto foot_r = Player->GetBonePos("foot_r", {});
                         ImVec2 foot_rPoSC;
                         auto neck_01 = Player->GetBonePos("neck_01", {});
                         ImVec2 neck_01PoSC;
                         auto spine_01 = Player->GetBonePos("spine_01", {});
                         ImVec2 spine_01PoSC;
                         auto spine_02 = Player->GetBonePos("spine_02", {});
                         ImVec2 spine_02PoSC;
                         auto spine_03 = Player->GetBonePos("spine_03", {});
						 ImVec2 spine_03PoSC;
						 
                                  if (W2S(HeadPos, (FVector2D *) & headPosSC) && W2S(upper_r, (FVector2D *) & upper_rPoSC) && W2S(upper_l, (FVector2D *) & upper_lPoSC) && W2S(lowerarm_r, (FVector2D *) & lowerarm_rPoSC) && W2S(hand_r, (FVector2D *) & hand_rPoSC) && W2S(lowerarm_l, (FVector2D *) & lowerarm_lSC) && W2S(hand_l, (FVector2D *) & hand_lPoSC) && W2S(thigh_l, (FVector2D *) & thigh_lPoSC) && W2S(calf_l, (FVector2D *) & calf_lPoSC) && W2S(foot_l, (FVector2D *) & foot_lPoSC) && W2S(thigh_r, (FVector2D *) & thigh_rPoSC) && W2S(calf_r, (FVector2D *) & calf_rPoSC) && W2S(foot_r, (FVector2D *) & foot_rPoSC) && W2S(neck_01, (FVector2D *) & neck_01PoSC) && W2S(pelvis, (FVector2D *) & pelvisPoSC) && W2S(RootPos, (FVector2D *) & RootPosSC) && W2S(spine_01, (FVector2D *) & spine_01PoSC)&& W2S(spine_02, (FVector2D *) & spine_02PoSC)&& W2S(spine_03, (FVector2D *) & spine_03PoSC)) {
                                  if (Config.ESPMenu.Line) {       
                                  
                                  
                                  
                            bool isvibl = !localController->LineOfSightTo(Player, {0, 0, 0}, true);
                            long SCOLOR1 = isvibl ? IM_COL32(0, 255, 0, 255) : IM_COL32(255, 0, 0, 255);
                            
                            
                                draw->AddLine({(float) glWidth / 2, 0}, headPosSC, SCOLOR1, 0.7f);
                                }
							
								long SCOLOR1 = IM_COL32(0, 255, 0, 255);
								
                             /*   if (Config.ESPMenu.Box) {
                                    FVector BoxSize;
                                    BoxSize.X = 60.f; // Height
                                    BoxSize.Y = 75.f; // Front
                                    BoxSize.Z = 165.f; // Height
                                    Box3D(draw, Player->K2_GetActorLocation(), BoxSize, PlayerBoxClrCf);
                                }*/
                                

                           /*     if (Config.ESPMenu.Skeleton) {
                                    static std::vector<std::string> right_arm{"neck_01",
                                                                              "clavicle_r",
                                                                              "upperarm_r",
                                                                              "lowerarm_r",
                                                                              "hand_r", "item_r"};
                                    static std::vector<std::string> left_arm{"neck_01",
                                                                             "clavicle_l",
                                                                             "upperarm_l",
                                                                             "lowerarm_l",
                                                                             "hand_l", "item_l"};
                                    static std::vector<std::string> spine{"Head", "neck_01",
                                                                          "spine_03",
                                                                          "spine_02", "spine_01",
                                                                          "pelvis"};
                                    static std::vector<std::string> lower_right{"pelvis", "thigh_r",
                                                                                "calf_r", "foot_r"};
                                    static std::vector<std::string> lower_left{"pelvis", "thigh_l",
                                                                               "calf_l", "foot_l"};
                                    static std::vector<std::vector<std::string>> skeleton{right_arm,
                                                                                          left_arm,
                                                                                          spine,
                                                                                          lower_right,
                                                                                          lower_left};

                                    for (auto &boneStructure: skeleton) {
                                        std::string lastBone;
                                        for (std::string &currentBone: boneStructure) {
                                            if (!lastBone.empty()) {
                                                ImVec2 boneFrom, boneTo;
                                                if (W2S(Player->GetBonePos(lastBone.c_str(), {}),
                                                        (FVector2D *) &boneFrom) &&
                                                    W2S(Player->GetBonePos(currentBone.c_str(), {}),
                                                        (FVector2D *) &boneTo)) {
                                                    draw->AddLine(boneFrom, boneTo,
                                                                  PlayerBoxClrCf, Config.ESPSettings.LineSize);
                                                }
                                            }
                                            lastBone = currentBone;
                                        }
                                    }
                                }*/
                                
                                
                                                             if (Config.ESPMenu.Skeleton) {
                             int SCOLOR23;
                             int SCOLOR24;
                          
                              if (Player->bIsAI) {
                            SCOLOR23 =  IM_COL32(255, 255, 255, 255);
				         	SCOLOR24 = IM_COL32(0, 255, 255, 255); 
				         	} else {
				         	SCOLOR23 =  IM_COL32(0, 255, 0, 255);
				         	SCOLOR24 = IM_COL32(255, 0, 0, 255); 
				         	}

							bool Visble = false;
							float boxWidth = 7.f- Distance * 0.03;

                  //          if (Config.PlayerESP.Skeleton) {
								
   				        if(!localController->LineOfSightTo(localController->PlayerCameraManager, neck_01, false))
						{
						Visble = true;

						draw->AddLine( { upper_rPoSC.x, upper_rPoSC.y }, neck_01PoSC, SCOLOR23,0.6f );
						

						}else
						draw->AddLine( { upper_rPoSC.x, upper_rPoSC.y }, neck_01PoSC, SCOLOR24,0.6f );
						

						
						if(!localController->LineOfSightTo(localController->PlayerCameraManager, neck_01, false))
						{
						Visble = true;

						draw->AddLine( { upper_lPoSC.x, upper_lPoSC.y }, neck_01PoSC, SCOLOR23,0.6f );
						
						}else
						draw->AddLine( { upper_lPoSC.x, upper_lPoSC.y }, neck_01PoSC, SCOLOR24,0.6f );
						

				
						

						if(!localController->LineOfSightTo(localController->PlayerCameraManager, lowerarm_r, false))
						{
						Visble = true;

						draw->AddLine( { upper_rPoSC.x, upper_rPoSC.y }, lowerarm_rPoSC,SCOLOR23, 2.0f );
						

						}else
						draw->AddLine( { upper_rPoSC.x, upper_rPoSC.y }, lowerarm_rPoSC,SCOLOR24, 2.0f );
						

						

						
						
						if(!localController->LineOfSightTo(localController->PlayerCameraManager, hand_r, false))
						{
						Visble = true;

						draw->AddLine( { lowerarm_rPoSC.x, lowerarm_rPoSC.y }, hand_rPoSC,SCOLOR23, 2.0f );
						

						}else
						draw->AddLine( { lowerarm_rPoSC.x, lowerarm_rPoSC.y }, hand_rPoSC,SCOLOR24, 2.0f );
			


						

						
						if(!localController->LineOfSightTo(localController->PlayerCameraManager, lowerarm_r, false))
						{
						Visble = true;

						draw->AddLine( { upper_lPoSC.x, upper_lPoSC.y }, lowerarm_lSC, SCOLOR23,0.6f );
						
						}else
						draw->AddLine( { upper_lPoSC.x, upper_lPoSC.y }, lowerarm_lSC, SCOLOR24,0.6f );
						
						if(!localController->LineOfSightTo(localController->PlayerCameraManager, hand_l, false))
						{
						Visble = true;
						
						draw->AddLine( { lowerarm_lSC.x, lowerarm_lSC.y }, hand_lPoSC, SCOLOR23,0.6f );
						}else
						draw->AddLine( { lowerarm_lSC.x, lowerarm_lSC.y }, hand_lPoSC, SCOLOR24,0.6f );
						
						if(!localController->LineOfSightTo(localController->PlayerCameraManager, thigh_l, false))
						{
						Visble = true;
						
						draw->AddLine( { thigh_rPoSC.x, thigh_rPoSC.y }, thigh_lPoSC, SCOLOR23,0.6f );
						}else
						draw->AddLine( { thigh_rPoSC.x, thigh_rPoSC.y }, thigh_lPoSC, SCOLOR24,0.6f );
						
						if(!localController->LineOfSightTo(localController->PlayerCameraManager, calf_l, false))
						{
						Visble = true;
						
						draw->AddLine( { thigh_lPoSC.x, thigh_lPoSC.y }, calf_lPoSC, SCOLOR23,0.6f );
						}else
						draw->AddLine( { thigh_lPoSC.x, thigh_lPoSC.y }, calf_lPoSC, SCOLOR24,0.6f );
						
						if(!localController->LineOfSightTo(localController->PlayerCameraManager, foot_l, false))
						{
						Visble = true;
						
						draw->AddLine( { calf_lPoSC.x, calf_lPoSC.y }, foot_lPoSC, SCOLOR23,0.6f );
						}else
						draw->AddLine( { calf_lPoSC.x, calf_lPoSC.y }, foot_lPoSC, SCOLOR24,0.6f );
					    
						if(!localController->LineOfSightTo(localController->PlayerCameraManager, calf_r, false))
						{
						Visble = true;
						
						draw->AddLine( { thigh_rPoSC.x, thigh_rPoSC.y }, calf_rPoSC, SCOLOR23,0.6f );
						}else
						draw->AddLine( { thigh_rPoSC.x, thigh_rPoSC.y }, calf_rPoSC, SCOLOR24,0.6f );
						
						if(!localController->LineOfSightTo(localController->PlayerCameraManager, foot_r, false))
						{
						Visble = true;
						
						draw->AddLine( { calf_rPoSC.x, calf_rPoSC.y }, foot_rPoSC, SCOLOR23,0.6f );
						}else
						draw->AddLine( { calf_rPoSC.x, calf_rPoSC.y }, foot_rPoSC, SCOLOR24,0.6f );
						if(!localController->LineOfSightTo(localController->PlayerCameraManager, pelvis, false))
						{
						Visble = true;					
						draw->AddLine( { neck_01PoSC.x, neck_01PoSC.y }, pelvisPoSC, SCOLOR23,0.6f );
						}else
						draw->AddLine( { neck_01PoSC.x, neck_01PoSC.y }, pelvisPoSC, SCOLOR24,0.6f );					
						if(!localController->LineOfSightTo(localController->PlayerCameraManager, HeadPos, false))
						{
						Visble = true;
				//		boxwidth = 1.7f - 0.003*Distance
						draw->AddLine( { neck_01PoSC.x, neck_01PoSC.y }, headPosSC, SCOLOR23,0.6f );
						//draw->AddCircle({HeadPosSC.x, HeadPosSC.y - Config.Test}, boxWidth, SCOLOR23, 1000000, 1.0f);                             
						}else
						draw->AddLine( { neck_01PoSC.x, neck_01PoSC.y }, headPosSC, SCOLOR24,0.6f );
						//draw->AddCircle({HeadPosSC.x, HeadPosSC.y-Config.Test}, boxWidth, SCOLOR24, 100000, 1.0f);

                             }

                          if (Config.ESPMenu.Health) {
                          bool isvibl = !localController->LineOfSightTo(Player, {0, 0, 0}, true);
                            long SCOLOR1 = isvibl ? IM_COL32(0, 255, 0, 255) : IM_COL32(255, 0, 0, 255);                             
                                                             
                          
                          
                          
                                    int CurHP = (int) std::max(0, std::min((int) Player->Health,
                                                                           (int) Player->HealthMax));
                                    int MaxHP = (int) Player->HealthMax;

                                    long HPColor = SCOLOR1;//IM_COL32(255, 0, 0, 255);
                                    long HPRectColor = IM_COL32(0, 0, 0, 255);

                                    if (Player->Health == 0.0f && !Player->bDead) {
                                        HPColor = IM_COL32(56, 183, 215, 199);
									 HPRectColor = IM_COL32(57, 183, 215,255);

                                        CurHP = Player->NearDeathBreath;
                                        if (Player->NearDeatchComponent) {
                                            MaxHP = Player->NearDeatchComponent->BreathMax;
                                        }
                                    }

                                    float boxWidth = density / 4.1f;
                                    boxWidth -= std::min(((boxWidth / 2) / 500.0f) * Distance,
                                                         boxWidth / 2);
                                    float boxHeight = boxWidth * 0.19f;


                                    ImVec2 vStart = {headPosSC.x - (boxWidth / 2),
                                                     headPosSC.y - (boxHeight * 1.5f)};

                                    ImVec2 vEndFilled = {vStart.x + (CurHP * boxWidth / MaxHP),
                                                         vStart.y + boxHeight};
                                    ImVec2 vEndRect = {vStart.x + boxWidth, vStart.y + boxHeight};

                                    draw->AddRectFilled(vStart, vEndFilled, HPColor, 3.2f, 240);
                                    draw->AddRect(vStart, vEndRect, HPRectColor, 3.2f, 240);
                                }
                               

                             /*   if (Config.ESPMenu.Weapon) {
                            auto Player1 = (ASTExtraPlayerCharacter *) Actor;
                                    auto WeaponManagerComponent = Player1->WeaponManagerComponent;
                                    if (WeaponManagerComponent) {
                                        auto CurrentWeaponReplicated = (ASTExtraShootWeapon *)WeaponManagerComponent->CurrentWeaponReplicated;
                                        if (CurrentWeaponReplicated) {
                                            auto WeaponId = (int)CurrentWeaponReplicated->GetWeaponID();
                                            auto Sbullet= CurrentWeaponReplicated->CurBulletNumInClip;
                                            auto Mbullet = CurrentWeaponReplicated->CurMaxBulletNumInOneClip;
                                            if (WeaponId) {
                                                std::string s;
                                                s += CurrentWeaponReplicated->GetWeaponName().ToString();
                                                s += " - ";
                                                s += std::to_string((int)Sbullet);
                                                s += "/";
                                                s += std::to_string((int)Mbullet);
                                                auto textSize = ImGui::CalcTextSize(s.c_str(), 0,
                                                                         ((float) density / 30.0f));
                                    
                                                draw->AddText(NULL,((float) density / 30.0f),
                                                              {RootPosSC.x - (textSize.x / 2),
                                                               RootPosSC.y + (textSize.y)}, IM_COL32(255, 255, 255, 255),
                                                               s.c_str());
                                            }
                                        }
                                    }
                                }*/
                                if (Config.ESPMenu.TeamID || Config.ESPMenu.Name || Config.ESPMenu.Distance ) {
                                    
                                    std::string s;
                                    
                                    
                                    if (Config.ESPMenu.TeamID) {
                                std::string sTeamID;
                                float a = 13;
                                sTeamID += std::to_string((int) Player->TeamID);
                                draw->AddText(nullptr, 19.f, ImVec2(headPosSC.x - healthLength + a, headPosSC.y - 30.0f), IM_COL32(0, 0, 0, 255), sTeamID.c_str());
                            }         

                                   if (Config.ESPMenu.Name) {
                                std::string s;
                                if (Player->bIsAI) {
                                    s += ICON_FA_MALE"[BOT]";
                                } else {
                                    s += Player->PlayerName.ToString();
                                }
                                draw->AddText(nullptr, 20.f, ImVec2(headPosSC.x - 28, headPosSC.y - 35.0f), IM_COL32(0, 0, 0, 255), s.c_str());
                            }
                                    
                                  /*  if (Config.ESPMenu.State) {
                                        auto State = playerstatus(Player->CurrentStates);
                                        if (!s.empty()) {
                                            s += " - ";
                                        }
                                        s += State;
                                        if (!s.empty()) {
                                            s += " - ";
                                        }
                                    }*/
                                    if (Config.ESPMenu.Distance) {
                                        if (!s.empty()) {
                                            s += " - ";
                                        }
                                        
                                        s += std::to_string((int) Distance);
                                        s += "M";
                                    }
                                    

                                    
                                    auto textSize = ImGui::CalcTextSize(s.c_str(), 0,
                                                                         ((float) density / 30.0f));
                                    
                                    draw->AddText(NULL, ((float) density / 30.0f),
                                                  {RootPosSC.x - (textSize.x / 2),
                                                   RootPosSC.y}, IM_COL32(255, 255, 255, 255),
                                                  s.c_str());
                                    
                                }
                            }
                    }
					     if (Config.ESPMenu.LootBox) 
					{
                            if (Actor->IsA(APickUpListWrapperActor::StaticClass())) {
                                auto LootBox = (APickUpListWrapperActor *) Actor;
                                auto RootComponent = Actor->RootComponent;
                                if (!RootComponent)
                                    continue;
                                float Distance = LootBox->GetDistanceTo(localPlayer) / 100.f;

                                FVector2D lootboxPos;
								if (Config.ESPMenu.LootBox) {
                                    FVector Hunt;
                            Hunt.X = 70.0f; 
                            Hunt.Y = 70.0f; // Front
                            Hunt.Z = 35.0f; // Height
                                Box3D(draw, LootBox->K2_GetActorLocation(), Hunt, IM_COL32(255, 255, 0, 255));							
                                } 
                                if (W2S(LootBox->K2_GetActorLocation(), &lootboxPos)) {
                                    std::string s = "";
                                    s += " [";
                                    s += std::to_string((int) Distance);
                                    s += "M]";

                                    draw->AddText(NULL, ((float) density / 15.0f),
                                                  {lootboxPos.X, lootboxPos.Y},
                                                  IM_COL32(255, 000, 000, 255), s.c_str());
                                }
                            }
                        }
                        
                               	if (Config.ESPMenu.Grenade) {
                            if (Actor->IsA(ASTExtraGrenadeBase::StaticClass())) {
                                auto Grenade = (ASTExtraGrenadeBase *) Actor;
                                auto RootComponent = Actor->RootComponent;
                                if (!RootComponent)
                                    continue;
                                float Distance = Grenade->GetDistanceTo(localPlayer) / 100.f;

                                FVector2D grenadePos;
                                if (Config.ESPMenu.Grenade) {
                                    FVector Cross;
                            Cross.X = 1000.0f; 
                            Cross.Y = 1000.0f; // Front
                            Cross.Z = 1.0f; // Height
                            
                            
                                Box3D(draw, Grenade->K2_GetActorLocation(), Cross, IM_COL32(255, 255, 255, 255));							
                                }
                                
                                
                                if (Config.ESPMenu.Grenade) {
                                    FVector Cross;
                            Cross.X = 700.0f; 
                            Cross.Y = 700.0f; // Front
                            Cross.Z = 3.0f; // Height
                                Box3D(draw, Grenade->K2_GetActorLocation(), Cross, IM_COL32(255, 200, 0, 255));							
                                                                }
                                                                
                         if (Config.ESPMenu.Grenade) {
                                    FVector Cross;
                            Cross.X = 400.0f; 
                            Cross.Y = 400.0f; // Front
                            Cross.Z = 3.0f; // Height
                                Box3D(draw, Grenade->K2_GetActorLocation(), Cross, IM_COL32(255, 0, 84, 255));							
                                                                }
                                                                
                                             if (Config.ESPMenu.Grenade) {
                                    FVector Cross;
                            Cross.X = 250.0f; 
                            Cross.Y = 250.0f; // Front
                            Cross.Z = 3.0f; // Height
                                Box3D(draw, Grenade->K2_GetActorLocation(), Cross, IM_COL32(255, 0, 0, 255));							
                                                                }
                                                                
                              if (Config.ESPMenu.Grenade) {
                                    FVector Cross;
                            Cross.X = 100.0f; 
                            Cross.Y = 100.0f; // Front
                            Cross.Z = 3.0f; // Height
                                Box3D(draw, Grenade->K2_GetActorLocation(), Cross, IM_COL32(255, 200, 0, 255));							
                                                                }                                  
                                

                                if (W2S(Grenade->K2_GetActorLocation(), &grenadePos)) {
                                    std::string s = "Grenade";
                                    s += "[";
                                    s += std::to_string((int) Distance);
                                    s += "M]";

                                    draw->AddText(NULL, ((float) density / 10.0f),
                                                  {grenadePos.X, grenadePos.Y},
                                                  IM_COL32(255, 255, 255, 255), s.c_str());
                                }
                            }
                        }
					
                            if (Config.ESPMenu.Vehicle)
						  {
                            if (Actors[i]->IsA(ASTExtraVehicleBase::StaticClass())) {
                                auto Vehicle = (ASTExtraVehicleBase *) Actors[i];

                                if (!Vehicle->Mesh)
                                    continue;

                                float Distance = Vehicle->GetDistanceTo(localPlayer) / 20.f;

                                FVector2D vehiclePos;
                            if (Config.ESPMenu.Vehicle) {
                                    FVector Hunt;
                            Hunt.X = 350.0f; 
                            Hunt.Y = 350.0f; // Front
                            Hunt.Z = 350.0f; // Height
                                Box3D(draw, Vehicle->K2_GetActorLocation(), Hunt, IM_COL32(255, 255, 255, 255));							
                                }
                                if (W2S(Vehicle->K2_GetActorLocation(), &vehiclePos)) {
                                    std::string s = "";
                                    if (Config.ESPMenu.Vehicle) {
                                        s += " [";
                                        s += std::to_string((int) Distance);
                                        s += "m]";
                                    }

                                    draw->AddText(NULL, ((float) density / 25.0f), {vehiclePos.X, vehiclePos.Y}, IM_COL32(255, 255, 255, 255), s.c_str());
                                }
                            }
                        }

                    if (Actors[i]->IsA(APickUpWrapperActor::StaticClass())) {
                        auto PickUp = (APickUpWrapperActor *) Actors[i];
                        if (Items[PickUp->DefineID.TypeSpecificID]) {
                            auto RootComponent = PickUp->RootComponent;
                            if (!RootComponent)
                                continue;

                            float Distance = PickUp->GetDistanceTo(localPlayer) / 100.f;

                            FVector2D itemPos;
                            if (W2S(PickUp->K2_GetActorLocation(), &itemPos)) {
                                std::string s;
                                uint32_t tc = 0xFF000000;

                                for (auto &category: items_data) {
                                    for (auto &item: category["Items"]) {
                                        if (item["itemId"] == PickUp->DefineID.TypeSpecificID) {
                                            s = item["itemName"].get<std::string>();
                                            tc = strtoul(
                                                    item["itemTextColor"].get<std::string>().c_str(),
                                                    0, 16);
                                            break;
                                        }
                                    }
                                }

                                s += " - ";
                                s += std::to_string((int) Distance);
                                s += "m";

                                draw->AddText(NULL, ((float) density / 25.0f),
                                              {itemPos.X, itemPos.Y}, tc, s.c_str());
                            }
                        }
                    }
                }
            }
        }

         g_LocalController = localController;
        g_LocalPlayer = localPlayer;






      /*  ImGui::SetNextWindowPos({(float) glWidth / 2, 50}, ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));
        ImGui::SetNextWindowSize(ImVec2(240.0f, 40.0f));
  ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 20.0f);
        ImGui::Begin("PonCount", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove);
        ImGui::SetCursorPos({25, 4});
        ImGui::Text(("Enemies: %d   Bots: %d"), totalEnemies , totalBots);
        ImGui::End();
        ImGui::PopStyleVar();*/







         
        if (totalEnemies + totalBots > 0) {
          int TotalCount = totalEnemies;
    
    ImGui::GetForegroundDrawList()->AddRectFilled({glWidth /1.73-200,40},{glWidth /1.73-10,80},ImColor(0,0,0,255), 20.0f);    
    sprintf(extra, "Players: %d", totalEnemies);
    ImGui::GetForegroundDrawList()->AddText({glWidth /2-55,45}, ImColor(255,255,255), extra);
    sprintf(extra, "Bots: %d    ", totalBots);
    ImGui::GetForegroundDrawList()->AddText({glWidth /2+35,45}, ImColor(255,255,255),extra);
   }





	if (Config.AimBot.FOV) {
               
           }










        fps.update();
    
}
	

// ======================================================================== //

std::string getClipboardText() {
    if (!g_App)
        return "";

    auto activity = g_App->activity;
    if (!activity)
        return "";

    auto vm = activity->vm;
    if (!vm)
        return "";

    auto object = activity->clazz;
    if (!object)
        return "";

    std::string result;

    JNIEnv *env;
    vm->AttachCurrentThread(&env, 0);
    {
        auto ContextClass = env->FindClass("android/content/Context");
        auto getSystemServiceMethod = env->GetMethodID(ContextClass, "getSystemService", "(Ljava/lang/String;)Ljava/lang/Object;");
        auto str = env->NewStringUTF("clipboard");
        auto clipboardManager = env->CallObjectMethod(object, getSystemServiceMethod, str);
        env->DeleteLocalRef(str);
        auto ClipboardManagerClass = env->FindClass("android/content/ClipboardManager");
        auto getText = env->GetMethodID(ClipboardManagerClass, "getText", "()Ljava/lang/CharSequence;");
        auto CharSequenceClass = env->FindClass("java/lang/CharSequence");
        auto toStringMethod = env->GetMethodID(CharSequenceClass, "toString", "()Ljava/lang/String;");
        auto text = env->CallObjectMethod(clipboardManager, getText);
        if (text) {
            str = (jstring) env->CallObjectMethod(text, toStringMethod);
            result = env->GetStringUTFChars(str, 0);
            env->DeleteLocalRef(str);
            env->DeleteLocalRef(text);
        }

        env->DeleteLocalRef(CharSequenceClass);
        env->DeleteLocalRef(ClipboardManagerClass);
        env->DeleteLocalRef(clipboardManager);
        env->DeleteLocalRef(ContextClass);
    }
    vm->DetachCurrentThread();

    return result;
}
// ======================================================================== //
const char *GetAndroidID(JNIEnv *env, jobject context) {
    jclass contextClass = env->FindClass(/*android/content/Context*/ StrEnc("`L+&0^[S+-:J^$,r9q92(as", "\x01\x22\x4F\x54\x5F\x37\x3F\x7C\x48\x42\x54\x3E\x3B\x4A\x58\x5D\x7A\x1E\x57\x46\x4D\x19\x07", 23).c_str());
    jmethodID getContentResolverMethod = env->GetMethodID(contextClass, /*getContentResolver*/ StrEnc("E8X\\7r7ys_Q%JS+L+~", "\x22\x5D\x2C\x1F\x58\x1C\x43\x1C\x1D\x2B\x03\x40\x39\x3C\x47\x3A\x4E\x0C", 18).c_str(), /*()Landroid/content/ContentResolver;*/ StrEnc("8^QKmj< }5D:9q7f.BXkef]A*GYLNg}B!/L", "\x10\x77\x1D\x2A\x03\x0E\x4E\x4F\x14\x51\x6B\x59\x56\x1F\x43\x03\x40\x36\x77\x28\x0A\x08\x29\x24\x44\x33\x0B\x29\x3D\x08\x11\x34\x44\x5D\x77", 35).c_str());
    jclass settingSecureClass = env->FindClass(/*android/provider/Settings$Secure*/ StrEnc("T1yw^BCF^af&dB_@Raf}\\FS,zT~L(3Z\"", "\x35\x5F\x1D\x05\x31\x2B\x27\x69\x2E\x13\x09\x50\x0D\x26\x3A\x32\x7D\x32\x03\x09\x28\x2F\x3D\x4B\x09\x70\x2D\x29\x4B\x46\x28\x47", 32).c_str());
    jmethodID getStringMethod = env->GetStaticMethodID(settingSecureClass, /*getString*/ StrEnc("e<F*J5c0Y", "\x02\x59\x32\x79\x3E\x47\x0A\x5E\x3E", 9).c_str(), /*(Landroid/content/ContentResolver;Ljava/lang/String;)Ljava/lang/String;*/ StrEnc("$6*%R*!XO\"m18o,0S!*`uI$IW)l_/_knSdlRiO1T`2sH|Ouy__^}%Y)JsQ:-\"(2_^-$i{?H", "\x0C\x7A\x4B\x4B\x36\x58\x4E\x31\x2B\x0D\x0E\x5E\x56\x1B\x49\x5E\x27\x0E\x69\x0F\x1B\x3D\x41\x27\x23\x7B\x09\x2C\x40\x33\x1D\x0B\x21\x5F\x20\x38\x08\x39\x50\x7B\x0C\x53\x1D\x2F\x53\x1C\x01\x0B\x36\x31\x39\x46\x0C\x15\x43\x2B\x05\x30\x15\x41\x43\x46\x55\x70\x0D\x59\x56\x00\x15\x58\x73", 71).c_str());

    auto obj = env->CallObjectMethod(context, getContentResolverMethod);
    auto str = (jstring) env->CallStaticObjectMethod(settingSecureClass, getStringMethod, obj, env->NewStringUTF(/*android_id*/ StrEnc("ujHO)8OfOE", "\x14\x04\x2C\x3D\x46\x51\x2B\x39\x26\x21", 10).c_str()));
    return env->GetStringUTFChars(str, 0);
}

const char *GetDeviceModel(JNIEnv *env) {
    jclass buildClass = env->FindClass(/*android/os/Build*/ StrEnc("m5I{GKGWBP-VOxkA", "\x0C\x5B\x2D\x09\x28\x22\x23\x78\x2D\x23\x02\x14\x3A\x11\x07\x25", 16).c_str());
    jfieldID modelId = env->GetStaticFieldID(buildClass, /*MODEL*/ StrEnc("|}[q:", "\x31\x32\x1F\x34\x76", 5).c_str(), /*Ljava/lang/String;*/ StrEnc(".D:C:ETZ1O-Ib&^h.Y", "\x62\x2E\x5B\x35\x5B\x6A\x38\x3B\x5F\x28\x02\x1A\x16\x54\x37\x06\x49\x62", 18).c_str());

    auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
    return env->GetStringUTFChars(str, 0);
}

const char *GetDeviceBrand(JNIEnv *env) {
    jclass buildClass = env->FindClass(/*android/os/Build*/ StrEnc("0iW=2^>0zTRB!B90", "\x51\x07\x33\x4F\x5D\x37\x5A\x1F\x15\x27\x7D\x00\x54\x2B\x55\x54", 16).c_str());
    jfieldID modelId = env->GetStaticFieldID(buildClass, /*BRAND*/ StrEnc("@{[FP", "\x02\x29\x1A\x08\x14", 5).c_str(), /*Ljava/lang/String;*/ StrEnc(".D:C:ETZ1O-Ib&^h.Y", "\x62\x2E\x5B\x35\x5B\x6A\x38\x3B\x5F\x28\x02\x1A\x16\x54\x37\x06\x49\x62", 18).c_str());

    auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
    return env->GetStringUTFChars(str, 0);
}

const char *GetPackageName(JNIEnv *env, jobject context) {
    jclass contextClass = env->FindClass(/*android/content/Context*/ StrEnc("`L+&0^[S+-:J^$,r9q92(as", "\x01\x22\x4F\x54\x5F\x37\x3F\x7C\x48\x42\x54\x3E\x3B\x4A\x58\x5D\x7A\x1E\x57\x46\x4D\x19\x07", 23).c_str());
    jmethodID getPackageNameId = env->GetMethodID(contextClass, /*getPackageName*/ StrEnc("YN4DaP)!{wRGN}", "\x3E\x2B\x40\x14\x00\x33\x42\x40\x1C\x12\x1C\x26\x23\x18", 14).c_str(), /*()Ljava/lang/String;*/ StrEnc("VnpibEspM(b]<s#[9cQD", "\x7E\x47\x3C\x03\x03\x33\x12\x5F\x21\x49\x0C\x3A\x13\x20\x57\x29\x50\x0D\x36\x7F", 20).c_str());

    auto str = (jstring) env->CallObjectMethod(context, getPackageNameId);
    return env->GetStringUTFChars(str, 0);
}

const char *GetDeviceUniqueIdentifier(JNIEnv *env, const char *uuid) {
    jclass uuidClass = env->FindClass(/*java/util/UUID*/ StrEnc("B/TxJ=3BZ_]SFx", "\x28\x4E\x22\x19\x65\x48\x47\x2B\x36\x70\x08\x06\x0F\x3C", 14).c_str());

    auto len = strlen(uuid);

    jbyteArray myJByteArray = env->NewByteArray(len);
    env->SetByteArrayRegion(myJByteArray, 0, len, (jbyte *) uuid);

    jmethodID nameUUIDFromBytesMethod = env->GetStaticMethodID(uuidClass, /*nameUUIDFromBytes*/ StrEnc("P6LV|'0#A+zQmoat,", "\x3E\x57\x21\x33\x29\x72\x79\x67\x07\x59\x15\x3C\x2F\x16\x15\x11\x5F", 17).c_str(), /*([B)Ljava/util/UUID;*/ StrEnc("sW[\"Q[W3,7@H.vT0) xB", "\x5B\x0C\x19\x0B\x1D\x31\x36\x45\x4D\x18\x35\x3C\x47\x1A\x7B\x65\x7C\x69\x3C\x79", 20).c_str());
    jmethodID toStringMethod = env->GetMethodID(uuidClass, /*toString*/ StrEnc("2~5292eW", "\x46\x11\x66\x46\x4B\x5B\x0B\x30", 8).c_str(), /*()Ljava/lang/String;*/ StrEnc("P$BMc' #j?<:myTh_*h0", "\x78\x0D\x0E\x27\x02\x51\x41\x0C\x06\x5E\x52\x5D\x42\x2A\x20\x1A\x36\x44\x0F\x0B", 20).c_str());

    auto obj = env->CallStaticObjectMethod(uuidClass, nameUUIDFromBytesMethod, myJByteArray);
    auto str = (jstring) env->CallObjectMethod(obj, toStringMethod);
    return env->GetStringUTFChars(str, 0);
}

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *) userp;

    mem->memory = (char *) realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        return 0;
    }

    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

//=========================MAIN LOGIN =================//
std::string Login(const char *user_key) {
    if (!g_App)
        return "Internal Error";

    auto activity = g_App->activity;
    if (!activity)
        return "Internal Error";

    auto vm = activity->vm;
    if (!vm)
        return "Internal Error";

    auto object = activity->clazz;
    if (!object)
        return "Internal Error";

    JNIEnv *env;
    vm->AttachCurrentThread(&env, 0);

    std::string hwid = user_key;
    hwid += GetAndroidID(env, object);
    hwid += GetDeviceModel(env);
    hwid += GetDeviceBrand(env);

    std::string UUID = GetDeviceUniqueIdentifier(env, hwid.c_str());

    vm->DetachCurrentThread();

    std::string errMsg;

    struct MemoryStruct chunk{};
    chunk.memory = (char *) malloc(1);
    chunk.size = 0;

    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();

    
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ᴍᴀᴅᴇʙʏɴᴏᴄᴀꜱʜ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
   if (curl) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, /*POST*/ StrEnc(",IL=", "\x7C\x06\x1F\x69", 4).c_str());
        std::string api_key = OBFUSCATE("https://key-panel.xyz/ABOUDxSONIC/connect");
        curl_easy_setopt(curl, CURLOPT_URL, (api_key.c_str()));
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, /*https*/ StrEnc("!mLBO", "\x49\x19\x38\x32\x3C", 5).c_str());
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, /*Content-Type: application/x-www-form-urlencoded*/ StrEnc("@;Ls\\(KP4Qrop`b#d3094/r1cf<c<=H)AiiBG6i|Ta66s2[", "\x03\x54\x22\x07\x39\x46\x3F\x7D\x60\x28\x02\x0A\x4A\x40\x03\x53\x14\x5F\x59\x5A\x55\x5B\x1B\x5E\x0D\x49\x44\x4E\x4B\x4A\x3F\x04\x27\x06\x1B\x2F\x6A\x43\x1B\x10\x31\x0F\x55\x59\x17\x57\x3F", 47).c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        char data[4096];
        sprintf(data, /*game=PUBG&user_key=%s&serial=%s*/ StrEnc("qu2yXK,YkJyGD@ut0.u~Nb'5(:.:chK", "\x16\x14\x5F\x1C\x65\x1B\x79\x1B\x2C\x6C\x0C\x34\x21\x32\x2A\x1F\x55\x57\x48\x5B\x3D\x44\x54\x50\x5A\x53\x4F\x56\x5E\x4D\x38", 31).c_str(), user_key, UUID.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &chunk);

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            try {
                json result = json::parse(chunk.memory);
                if (result[/*status*/ StrEnc("(>_LBm", "\x5B\x4A\x3E\x38\x37\x1E", 6).c_str()] == true) {
                    std::string token = result[/*data*/ StrEnc("fAVA", "\x02\x20\x22\x20", 4).c_str()][/*token*/ StrEnc("{>3Lr", "\x0F\x51\x58\x29\x1C", 5).c_str()].get<std::string>();
                    
                    

                    
                    
                    time_t rng = result[/*data*/ StrEnc("fAVA", "\x02\x20\x22\x20", 4).c_str()][/*rng*/ StrEnc("+n,", "\x59\x00\x4B", 3).c_str()].get<time_t>();
                    if (rng + 30 > time(0)) {
                        std::string auth = /*PUBG*/ StrEnc("Q*) ", "\x01\x7F\x6B\x67", 4).c_str();;
                        auth += "-";
                        auth += user_key;
                        auth += "-";
                        auth += UUID;
                        auth += "-";
                        auth += /*Vm8Lk7Uj2JmsjCPVPVjrLa7zgfx3uz9E*/ StrEnc("-2:uwZdV^%]?{{wHs2V,+(^NJU;kC*_{", "\x7B\x5F\x02\x39\x1C\x6D\x31\x3C\x6C\x6F\x30\x4C\x11\x38\x27\x1E\x23\x64\x3C\x5E\x67\x49\x69\x34\x2D\x33\x43\x58\x36\x50\x66\x3E", 32).c_str();
                        std::string outputAuth = Tools::CalcMD5(auth);

                        g_Token = token;
                        g_Auth = outputAuth;

                        bValid = g_Token == g_Auth;
                    }
                } else {
                    errMsg = result[/*reason*/ StrEnc("LW(3(c", "\x3E\x32\x49\x40\x47\x0D", 6).c_str()].get<std::string>();
                }
            } catch (json::exception &e) {
                errMsg = "{";
                errMsg += e.what();
                errMsg += "}\n{";
                errMsg += chunk.memory;
                errMsg += "}";
            }
        } else {
            errMsg = curl_easy_strerror(res);
        }
    }
    curl_easy_cleanup(curl);
    vm->DetachCurrentThread();

    return bValid ? "OK" : errMsg;
}


// ======================================================================== //

// ======================================================================== //
#define IM_CLAMP(V, MN, MX)     ((V) < (MN) ? (MN) : (V) > (MX) ? (MX) : (V))
namespace Settings
{
    static int Tab = 1;
}


EGLBoolean (*orig_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
    EGLBoolean _eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);
    if (glWidth <= 0 || glHeight <= 0)
    return orig_eglSwapBuffers(dpy, surface);
    if (!g_App)
    return orig_eglSwapBuffers(dpy, surface);
    screenWidth = ANativeWindow_getWidth(g_App->window);
    screenHeight = ANativeWindow_getHeight(g_App->window);
    density = AConfiguration_getDensity(g_App->config);


    if (!initImGui) {
        ImGui::CreateContext();

        ImGuiStyle& style = ImGui::GetStyle();
        style.WindowRounding = 8.0f;
        style.FrameRounding = 7.0f;
        style.ScrollbarRounding = 9;
		style.WindowBorderSize = 4;//2
		style.FrameBorderSize = 3.5;// обводки кнопок

		

        
        style.WindowPadding = ImVec2(6, 8);
        style.FramePadding = ImVec2(4, 3);
        style.Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
        style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.36f, 0.42f, 0.47f, 1.00f);
        style.Colors[ImGuiCol_WindowBg] = ImColor(29, 34, 38, 255);
        style.Colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
        style.Colors[ImGuiCol_Border] = ImColor(0, 158, 255, 155);// Zolo Yellow
        style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        style.Colors[ImGuiCol_FrameBg] = ImColor(40, 50, 60, 255);// головне меню
        style.Colors[ImGuiCol_FrameBgHovered] = ImColor(40, 50, 60, 255);
        style.Colors[ImGuiCol_FrameBgActive] = ImColor(40, 50, 60, 255);
        style.Colors[ImGuiCol_TitleBg] = ImColor(0, 0, 0, 155);// сверху окно
        style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(0, 0, 0, 155);
        style.Colors[ImGuiCol_TitleBgActive] = ImColor(0, 0, 0, 255); //think title bar
        style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
        style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.39f);
        style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
        style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.18f, 0.22f, 0.25f, 1.00f);
        style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.09f, 0.21f, 0.31f, 1.00f);
        style.Colors[ImGuiCol_CheckMark] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
        style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
        style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
        style.Colors[ImGuiCol_Button] = ImColor(51, 64, 73, 255);
        style.Colors[ImGuiCol_ButtonHovered] = ImColor(51, 64, 73, 255);
        style.Colors[ImGuiCol_ButtonActive] = ImColor(51, 64, 73, 255);
        style.Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.15f, 0.19f, 0.55f);
        style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.16f, 0.19f, 0.15f, 1.00f);
        style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.16f, 0.19f, 0.15f, 1.00f);
        style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
        style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
        style.Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
        style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
        style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
        style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
		style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);



        style.ScaleAllSizes(std::max(2.0f, density / 150.0f));//1
        style.ScrollbarSize /= 1;//1

        ImGui_ImplAndroid_Init();
        ImGui_ImplOpenGL3_Init("#version 300 es");

        ImGuiIO &io = ImGui::GetIO();

        io.ConfigWindowsMoveFromTitleBarOnly = true;
        io.IniFilename = NULL;

        static const ImWchar icons_ranges[] = { 0xf000, 0xf3ff, 0 };
        ImFontConfig icons_config;

        ImFontConfig CustomFont;
        CustomFont.FontDataOwnedByAtlas = false;

        icons_config.MergeMode = true;
        icons_config.PixelSnapH = true;
        icons_config.OversampleH = 2.5;
        icons_config.OversampleV = 2.5;

       io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom), sizeof(Custom), 21.f, &CustomFont);
        io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 19.0f, &icons_config, icons_ranges);

        ImFontConfig cfg;
        cfg.SizePixels = ((float) density / 25.0f);
        io.Fonts->AddFontDefault(&cfg);

        memset(&Config, 0, sizeof(sConfig));
// ===============(================ESPCOLOR ================================== //

           
		
		
         Config.ColorsESP.Line = CREATE_COLOR(255, 0, 0, 255);
		 Config.ColorsESP.Line1 = CREATE_COLOR(255, 255, 255, 255);
		 Config.ColorsESP.Linebot = CREATE_COLOR(255, 0, 0, 255);
		 Config.ColorsESP.Linebot1 = CREATE_COLOR(255, 255, 255, 255);
		 Config.ColorsESP.Skeletonbot = CREATE_COLOR(255, 255, 255, 255);
	     Config.ColorsESP.Boxbot = CREATE_COLOR(255, 255, 255, 255);
         Config.ColorsESP.Box = CREATE_COLOR(255, 0, 255, 255);
         Config.ColorsESP.Name = CREATE_COLOR(255, 0, 0, 255);
         Config.ColorsESP.Distance = CREATE_COLOR(255, 0, 255, 255);
         Config.ColorsESP.Skeleton = CREATE_COLOR(255, 0, 0, 255);
         Config.ColorsESP.Vehicle = CREATE_COLOR(255, 0, 0, 255);
       // Config.ColorsESP.Items = CREATE_COLOR(255, 255, 255, 255);
	     Config.ColorsESP.Fov = CREATE_COLOR(255, 0, 0, 255);
         Config.SilentAim.Cross  = 36.0f;
        initImGui = true;
	   
       

        for (auto &i : items_data, sniper1, rifle1, sub1, scope1, ammo1, atta1, medic1, grenade1, mag1, armor1) {
            for (auto &item : i["Items"]) {
                int r, g, b;
                sscanf(item["itemTextColor"].get<std::string>().c_str(), "#%02X%02X%02X", &r, &g, &b);
                ItemColors[item["itemId"].get<int>()] = CREATE_COLOR(r, g, b, 255);
            }
        }
        initImGui = true;
    }

		
		
		
		
		                    /*
*/
                        
		
		
	
	
	
	
	
	
	
	
    ImGuiIO &io = ImGui::GetIO();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(glWidth, glHeight);
    ImGui::NewFrame();

    DrawESP(ImGui::GetBackgroundDrawList());

           
ImGui::SetNextWindowSize(ImVec2((float) glWidth * 0.32f, (float) glHeight * 0.46f), ImGuiCond_Once); // 0.38 width 0.52 height
    if (ImGui::Begin(OBFUSCATE(" ZoloCheat - PUBG MOBILE - VIP 3.8 - | ESP + AIM2.0 :)" ), 0, ImGuiWindowFlags_NoBringToFrontOnFocus )) {
        static bool isLogin = false;

                if (!isLogin) {
            ImGui::Text("Please Login! (Copy Key to Clipboard)");

            ImGui::PushItemWidth(-1);
            static char s[64];
            ImGui::InputText("##key", s, sizeof s);
            ImGui::PopItemWidth();

            static std::string err;
            if (ImGui::Button("Login", ImVec2(ImGui::GetContentRegionAvailWidth(), 0))) {
                err = Login(s);
                if (err == "OK") {
                    isLogin = bValid && g_Auth == g_Token;
                }
            }
            
            
            //    auto paste
            auto key = getClipboardText();
            strncpy(s, key.c_str(), sizeof s);
            // auto login

            err = Login(s);
            if (err == "OK") {
                isLogin = bValid && g_Auth == g_Token;
            }
            ImGui::PopItemWidth();
            

            if (!err.empty() && err != "OK") {
                ImGui::Text("Error: %s", err.c_str());
            }
        } else {
        // MAKE BY @TITANIC_MOD
        
        // MAKE BY @TITANIC_MOD

        
        // MAKE BY @TITANIC_MOD
        
        
        // MAKE BY @TITANIC_MOD
        
        
					
	        ImGui::Columns(2);
            ImGui::SetColumnOffset(1.1, 150);// 1, 195
            {
                static ImVec4 active = ImColor(51, 64, 73, 255);
                static ImVec4 inactive = ImColor(51, 64, 73, 255);

                ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 1 ? active : inactive);
                if (ImGui::Button("VISUAL", ImVec2(135 - 15, 50)))// 180 - 15 50
                    Settings::Tab = 1;

                ImGui::Spacing();
                ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 2 ? active : inactive);
                if (ImGui::Button("ITEMS", ImVec2(135 - 15, 50)))
                    Settings::Tab = 2;
                ImGui::Spacing();
                ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 2 ? active : inactive);
                if (ImGui::Button("VEHICLE", ImVec2(135 - 15, 50)))
                    Settings::Tab = 3;

                ImGui::Spacing();
                ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 3 ? active : inactive);
                if (ImGui::Button("AIM MENU", ImVec2(135 - 15, 50)))
                    Settings::Tab = 4;

                ImGui::Spacing();
                ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 4 ? active : inactive);
                if (ImGui::Button("Extras", ImVec2(135 - 15, 50)))
                    Settings::Tab = 5;


                ImGui::PopStyleColor(5);

            }
            ImGui::NextColumn();

            if (Settings::Tab == 1) {
                
                            ImGui::Spacing();
							
				ImGui::Text( " ZoloCheat              FPS : %.2f", 1000 / io.Framerate );
						 if(ImGui::Checkbox("Enable All ESP",&Feu))
									{
										if(Feu == 1)
										{
											Config.ESPMenu.Health = true;
											Config.ESPMenu.Distance = true;
											Config.ESPMenu.TeamID = true;
											Config.ESPMenu.Line = true;
											Config.ESPMenu.Name = true;
											Config.ESPMenu.Skeleton = true;
										}
										if(Feu == 0)
										{
											Config.ESPMenu.Health = false;
											Config.ESPMenu.Distance = false;
											Config.ESPMenu.TeamID = false;
											Config.ESPMenu.Line = false;
											Config.ESPMenu.Name = false;
											Config.ESPMenu.Skeleton = false;
										}
									}
									                if (ImGui::BeginTable("split", 2));{
									                ImGui::TableNextColumn();            
                                    ImGui::Checkbox("Name", &Config.ESPMenu.Name);
                                    ImGui::TableNextColumn();
                                    ImGui::Checkbox("Line", &Config.ESPMenu.Line);
                                    ImGui::TableNextColumn();
                                    ImGui::Checkbox("Team ID", &Config.ESPMenu.TeamID);
                                    ImGui::TableNextColumn();
                                    ImGui::Checkbox("Distance", &Config.ESPMenu.Distance);
                                    ImGui::TableNextColumn();
                                    ImGui::Checkbox("Health", &Config.ESPMenu.Health);
                                    ImGui::TableNextColumn();
                                    ImGui::Checkbox("Skeleton", &Config.ESPMenu.Skeleton);
                                    ImGui::TableNextColumn();
                                    ImGui::EndTable();
				}			        if (ImGui::Combo("", &style_idx, "Simple Skeleton Color\0Per bone Skeleton Color\0None")) {
                switch (style_idx) {
                    
     			   
				   }}
                                    ImGui::Separator();
                                    ImGui::Text("Extras");
                                    ImGui::Separator();
                                    if (ImGui::BeginTable("split", 2));{
									                ImGui::TableNextColumn();
                                    ImGui::Checkbox("LootBox", &Config.LootBox);
                                    ImGui::TableNextColumn();
									ImGui::Checkbox("Grenade", &Config.Genn);
									ImGui::TableNextColumn();
                                    ImGui::EndTable();
				}			
				
                                    	} else if (Settings::Tab == 2) {
                                    	ImGui::Spacing();
                                    	ImGui::Text(" ITEMS MENU");
                                    	ImGui::Spacing();
                                    	ImGui::Spacing();
                                    	ImGui::Spacing();
                                    	ImGui::Text("Soon..");
                                    
					} else if (Settings::Tab == 3) {
                
                   ImGui::Spacing();
                   ImGui::Text("Vehicle");
                   ImGui::Separator();
                        ImGui::Checkbox("Enable", &Config.ShowVehicle);
                        ImGui::Checkbox("Speed", &Config.VehicleHealth);
                        
                    } else if (Settings::Tab == 4) {
                        
						ImGui::Spacing();
						  ImGui::Checkbox("Enable Aim2.0", &Config.AimBot.Enable);
						  ImGui::Checkbox("Ignore knocked", &Config.AimBot.IgnoreKnocked);
						  ImGui::Checkbox("Ignore bot", &Config.AimBot.IgnoreBot);
						  
						
						  ImGui::SliderFloat("FOV", &Config.AimBot.Cross, 0.0f, 200.0f);
			
				    	
                    static const char *triggers[] = {"None", "Shooting", "Scoping", "Both", "Any"};
                        ImGui::Combo("##Tr6igger", (int *) &Config.AimBot.Trigger, triggers, 5, -1);
			             ImGui::SameLine();
                    ImGui::Text(SelectLanguage("Trigger","触发方式："));
				                                     
				               static const char *targets[] = {"Auto", "Head", "Chest"};
                            ImGui::Combo("##T6arget", (int *) &Config.AimBot.Target, targets, 3, -1);
                    ImGui::SameLine();
                    ImGui::Text(SelectLanguage("Target","触发方式："));
							
						
									
						} else if (Settings::Tab == 5) {
                            ImGui::Spacing();
				
 				ImGui::Text("EXPIRY DATE-  ");
				ImGui::SameLine();
		        ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(252, 69, 3, 255));
				ImGui::Text("2023-07-25 22:10:15");
				ImGui::PopStyleColor();
				ImGui::Spacing();
				ImGui::Text("MAX DEVICES :  ");
				ImGui::SameLine();
		        ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(252, 69, 3, 255));
				ImGui::Text("1");
				ImGui::PopStyleColor();
				ImGui::Spacing();
				ImGui::Text("CHEAT TOKEN ID :   ");
				ImGui::SameLine();
	            ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(252, 69, 3, 255));
				ImGui::Text("723765");
				ImGui::PopStyleColor();
				ImGui::Spacing();
				ImGui::Text("CHEATS SAFE :  ");
				ImGui::SameLine();
				
			    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
				ImGui::Text("FULLY SAFE");
				ImGui::PopStyleColor();
				ImGui::Spacing();
			
        }
    }
}
						
            ImGui::End();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
         return orig_eglSwapBuffers(dpy, surface);
    }
   int32_t (*orig_onInputEvent1)(struct android_app *app, AInputEvent *inputEvent);
int32_t onInputEvent1(struct android_app *app, AInputEvent *inputEvent)
{
    if (initImGui)
    {
        ImGui_ImplAndroid_HandleInputEvent(inputEvent, {(float)screenWidth / (float)glWidth, (float)screenHeight / (float)glHeight});
    }
    return orig_onInputEvent1(app, inputEvent);
}

void (*orig_onInputEvent)(void *inputEvent, void *ex_ab, void *ex_ac);
void onInputEvent(void *inputEvent, void *ex_ab, void *ex_ac) {
orig_onInputEvent(inputEvent, ex_ab, ex_ac);if (initImGui) {ImGui_ImplAndroid_HandleInputEvent((AInputEvent*)inputEvent, {(float) screenWidth / (float) glWidth, (float) screenHeight / (float) glHeight});}}

[[noreturn]] void *bypass_thread(void *) {
    while (true) {
        auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

        auto localPlayer = g_LocalPlayer;
        auto localController = g_LocalController;
        if (localPlayer && localController) {

            if (Config.HighRisk.Recoil || Config.HighRisk.Shake || Config.HighRisk.Instant) {
                auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                if (WeaponManagerComponent) {
                    auto Slot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                    if ((int) Slot.GetValue() >= 1 && (int) Slot.GetValue() <= 3) {
                        auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
                        if (CurrentWeaponReplicated) {
                            auto ShootWeaponEntityComp = CurrentWeaponReplicated->ShootWeaponEntityComp;
                            auto ShootWeaponEffectComp = CurrentWeaponReplicated->ShootWeaponEffectComp;
                            if (ShootWeaponEntityComp && ShootWeaponEffectComp) {
                                if (Config.HighRisk.Recoil) {
                                    ShootWeaponEntityComp->AccessoriesVRecoilFactor = 0.0f;
                                    ShootWeaponEntityComp->AccessoriesHRecoilFactor = 0.0f;
                                    ShootWeaponEntityComp->AccessoriesRecoveryFactor = 0.0f;

                                    ShootWeaponEntityComp->RecoilKickADS = 0.0f;
                                }

                                if (Config.HighRisk.Shake) {
                                    ShootWeaponEffectComp->CameraShakeInnerRadius = 0.0f;
                                    ShootWeaponEffectComp->CameraShakeOuterRadius = 0.0f;
                                    ShootWeaponEffectComp->CameraShakFalloff = 0.0f;
                                }
								
	
                                if (Config.HighRisk.Instant) {
                                    ShootWeaponEntityComp->BulletRange = 100000.0f;
                                    ShootWeaponEntityComp->BaseImpactDamage = 100000.0f;
                                    ShootWeaponEntityComp->WeaponAimFOV = 100000.0f;
                                    ShootWeaponEntityComp->MaxDamageRate = 100000.0f;
                                    ShootWeaponEntityComp->MaxVelocityOffsetAddRate = 100000.0f;
                                    ShootWeaponEntityComp->BulletRange = 100000.0f;
                                    ShootWeaponEntityComp->BurstShootInterval = 0;
                                    ShootWeaponEntityComp->BurstShootCD = 100000.0f;
                                    ShootWeaponEntityComp->WeaponBodyLength = 100000.0f;
                                    ShootWeaponEntityComp->MaxBulletImpactFXClampDistance = 100000.0f;
                                }

                                if (Config.HighRisk.HitEffect) {
                                    ShootWeaponEntityComp->ExtraHitPerformScale = 200.0f;
								
								}
     
                                 if (Config.Unlock) {
auto objs = UObject::GetGlobalObjects();
for (int i = 0; i < objs.Num(); i++) {
auto Object = objs.GetByIndex(i);
if (isObjectInvalid(Object))
continue;
if (Object->IsA(USTExtraGameInstance::StaticClass())) {
                auto playerChar = (USTExtraGameInstance *) Object;      
                playerChar->UserDetailSetting.PUBGDeviceFPSDef = 90;   
                playerChar->UserDetailSetting.PUBGDeviceFPSLow = 90;
                playerChar->UserDetailSetting.PUBGDeviceFPSMid = 90;
                playerChar->UserDetailSetting.PUBGDeviceFPSHigh = 90;
                playerChar->UserDetailSetting.PUBGDeviceFPSHDR = 90;
                playerChar->UserDetailSetting.PUBGDeviceFPSUltralHigh = 90;
}
}


}     


         
         auto td = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - t1;
         std::this_thread::sleep_for(std::chrono::milliseconds(std::max(std::min(0LL, SLEEP_TIME - td),SLEEP_TIME)));

						
                                }
                            }
                        }
                    }
                }
            }
        

    auto td = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - t1;
        std::this_thread::sleep_for(std::chrono::milliseconds(std::max(std::min(0LL, SLEEP_TIME - td), SLEEP_TIME)));
    }
    return 0;
}








#define SLEEP_TIME 1000LL / 60LL
[[noreturn]] void *maps_thread(void *) {
    while (true) {
        auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

        std::vector<sRegion> tmp;
        char line[512];
        FILE *f = fopen("/proc/self/maps", "r");
        if (f) {
            while (fgets(line, sizeof line, f)) {
                uintptr_t start, end;
                char tmpProt[16];
                if (sscanf(line, "%" PRIXPTR "-%" PRIXPTR " %16s %*s %*s %*s %*s", &start, &end, tmpProt) > 0) {
                    if (tmpProt[0] != 'r') {
                        tmp.push_back({start, end});
                    }
                }
            }
            fclose(f);
            auto objs = UObject::GetGlobalObjects();
for (int i = 0; i < objs.Num(); i++) {
auto Object = objs.GetByIndex(i);
if (isObjectInvalid(Object))
continue;

if (平板视角) {
if (Object->IsA(ULocalPlayer::StaticClass())) {
auto playerChar = (ULocalPlayer *) Object;
playerChar->AspectRatioAxisConstraint = EAspectRatioAxisConstraint::AspectRatio_MaintainYFOV;
}	
} else
if (Object->IsA(ULocalPlayer::StaticClass())) {
auto playerChar = (ULocalPlayer *) Object;
playerChar->AspectRatioAxisConstraint = EAspectRatioAxisConstraint::AspectRatio_MaintainXFOV;
}}
        }

        auto td = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - t1;
        std::this_thread::sleep_for(std::chrono::milliseconds(std::max(std::min(0LL, SLEEP_TIME - td), SLEEP_TIME)));
    }
}

void *main_thread(void *) {
Offsets::g_UE4 = getBaseAddress("libUE4.so");
while (!Offsets::g_UE4) {
Offsets::g_UE4 = getBaseAddress("libUE4.so");
sleep(1);
}

Offsets::g_anogs = Utils::GetBaseAddress("libanogs.so");
while (!Offsets::g_anogs) {
Offsets::g_anogs = Utils::GetBaseAddress("libanogs.so");
sleep(1);
}

while (!g_App){
g_App = *(android_app **) (Offsets::g_UE4 + GNative);
sleep(1);}

void *input = dlopen_ex(OBFUSCATE("libinput.so"), 4);
while (!input) {input = dlopen_ex(OBFUSCATE("libinput.so"), 4);
sleep(1);}void *address = dlsym_ex(input, OBFUSCATE("_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE"));
HOOK(address, onInputEvent, &orig_onInputEvent);
dlclose_ex(input);
FName::GNames = GetGNames();
while (!FName::GNames) {
FName::GNames = GetGNames();
sleep(1);
}

UObject::GUObjectArray = (FUObjectArray *)(Offsets::g_UE4 + GObjectArray);

Tools::Hook((void *) DobbySymbolResolver(OBFUSCATE("/system/lib/libandroid_runtime.so"), OBFUSCATE("eglSwapBuffers")), (void *) _eglSwapBuffers, (void **) &orig_eglSwapBuffers);
 
Tools::Hook((void *) (Offsets::g_UE4 + 0x22E95B4), (void *) onInputEvent1,   (void **)&orig_onInputEvent1);

    return 0;
}
    

__attribute__((constructor))void _init() {
pthread_t t;
pthread_create(&t, 0, main_thread, 0);
}