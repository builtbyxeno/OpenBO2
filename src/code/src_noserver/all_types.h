#pragma once

struct MenuCell;
union vec4_t;
union DvarValue;
union DvarLimits;
union vec3_t;
struct cplane_s;
union GfxDrawSurf;
struct MaterialStreamRouting;
struct D3D11_MAPPED_SUBRESOURCE;
struct MaterialVertexDeclaration;
struct GfxVertexShaderLoadDef;
struct MaterialVertexShader;
struct GfxPixelShaderLoadDef;
struct MaterialPixelShader;
struct MaterialShaderArgument;
struct MaterialPass;
struct MaterialTechnique;
struct MaterialTechniqueSet;
struct Picmip;
struct GfxImage;
struct GfxStateBits;
struct Material;
struct PhysConstraint;
struct XNADDR;
union hudelem_color_t;
struct Operand;
struct Font_s;
struct rectDef_s;
struct PhysConstraints;
struct listBoxDef_s;
struct ExpressionStatement;
struct GenericEventScript;
struct animParamsDef_t;
struct HunkUser;
struct PhysPreset;
union Weapon;
struct PhysGeomInfo;
struct SndAlias;
struct SndAliasList;
union VariableUnion;
struct ChildVariableValue;
struct LeagueStats;
struct netProfileStream_t;
struct PhysGeomList;
struct windowDef_t;
union vec2_t;
struct textDef_s;
struct UILocalVar;
struct UILocalVarContext;
union SndEntHandle;
union __m128;
struct __m128d;
struct sockaddr;
struct LeagueOutcomes;
struct ddlEnumDef_t;
struct LerpEntityStateDestructibleHit;
struct renderOptions_s;
struct MantleState;
struct TracerDef;
struct SubpartyInfo;
struct score_s;
struct VariableValue;
struct EntHandle;
struct MemoryFile;
struct mover_positions_t;
struct svEntity_s;
struct WeaponAttachment;
struct clSnapshot_t;
struct trajectory_t;
struct viewClampState;
struct ai_orient_t;
struct actor_prone_info_s;
struct pathpoint_t;
struct path_t;
struct path_trim_t;
struct potential_threat_t;
struct SentientHandle;
struct actor_goal_s;
struct vis_cache_t;
struct col_prim_t;
struct gentity_t;
struct pathnode_t;
struct TurretInfo;
struct DObjAnimMat;
struct XSurfaceVertexInfo;
union GfxColor;
union PackedTexCoords;
union PackedUnitVec;
struct GfxPackedVertex;
struct XModel;
struct FxFloatRange;
struct FxElemMarkVisuals;
struct GfxLightDef;
union FxElemVisuals;
struct FxTrailDef;
struct DestructiblePiece;
struct DestructibleDef;
struct DestructibleState;
struct vehicle_node_t;
struct vehicle_physic_t;
struct VehicleJitter;
struct GraphFloat;
struct cLeafBrushNode_s;
struct ClipInfo;
struct cmodel_t;
struct TraceThreadInfo;
struct XAnimDeltaPart;
struct XAnimParts;
struct XAnim_s;
struct XAnimTree_s;
struct flameTable;
struct cStaticModel_s;
struct WeaponCamo;
struct WeaponDef;
struct WeaponAttachmentUnique;
struct WeaponVariantDef;
struct WeaponDobjInfo;
struct ddlStructDef_t;
struct ddlDef_t;
struct ddlState_t;
struct DObjSkelMat;
struct _iobuf;
struct CmdArgs;
struct msg_t;
struct netProfileInfo_t;
struct FastCriticalSection;
struct netchan_t;
struct NetField;
struct GfxMarkContext;
struct StringTable;
struct generic_avl_map_node_t;
struct CEntPlayerInfo;
struct ShaderConstantSet;
struct cpose_t;
struct cgVehicle_t;
struct centity_t;
struct GfxBloom;
struct GfxLight;
struct GfxViewport;
struct ExtraCamLodInfo;
struct lerpFrame_t;
struct clientInfo_t;
struct actorLerpFrame_t;
struct actorInfo_t;
struct visionSetVars_t;
struct transPlayerState_t;
struct bullet_hit_info_t;
struct snd_ambient_script_data;
struct ZBarrierDef;
struct animScriptItem_t;
struct animScript_t;
struct scr_animtree_t;
struct animScriptData_t;
struct scr_anim_s;
struct clientField_s;
struct bgsClientFields_s;
struct DObjModel_s;
struct DObj;
struct bot_goal_t;
struct bot_steering_t;
struct SpawnVar;
struct trigger_info_t;
struct com_parse_mark_t;
struct actorAntilagFrame_t;
struct vehicleAntilagFrame_t;
struct DynEntityDef;
struct ViewModelInfo;
struct GlassDef;
struct Glass;
struct IgnoreEntParams;
struct HWND__;
struct PolySet;
struct trDebugSphere_t;
struct HINSTANCE__;
struct GfxScaledPlacement;
struct ScreenPlacement;
struct GfxSceneDef;
struct GfxUI3DBackend;
struct GfxVertexBufferState;
struct GfxMatrix;
struct GfxAabbTree;
struct GfxDrawPrimArgs;
struct GfxMeshData;
struct trDebugString_t;
struct trDebugLine_t;
struct DebugGlobals;
struct GfxCmdBuf;
struct GfxParticleCloud;
struct GfxQRCodeBackend;
struct GfxDrawSurfListInfo;
struct GfxSunShadowProjection;
struct GfxSunShadow;
struct GfxFrameStats;
struct GfxCmdBufSourceState;
struct GfxLightingSH;
struct mnode_t;
struct GfxLightingSHQuantized;
struct VariantWind;
struct FX_WindInfo;
struct viewState_t;
struct WeaponComponentList;
struct WeaponFullDef;
struct ddlRoot_t;
struct FxImpactTable;
struct SndDuck;
struct SndAssetBankEntry;
struct SndPatch;
struct MapEnts;
struct DynEntityClient;
struct DynEntityColl;
struct clipMap_t;
struct ComPrimaryLight;
struct ComWorld;
struct pathnode_tree_t;
struct GameWorldSp;
struct GameWorldMp;
struct SunLightParseParams;
struct GfxLightCorona;
struct DpvsPlane;
struct GfxPortal;
struct GfxCell;
struct GfxWorldDraw;
struct GfxLightGrid;
struct GfxBrushModel;
struct sunflare_t;
struct GfxStaticModelInst;
struct srfTriangles_t;
struct GfxSurface;
struct GfxStaticModelDrawInst;
struct GfxWorld;
struct FontIcon;
struct MenuList;
struct LocalizeEntry;
struct SndCurve;
struct SndPan;
struct SndDriverGlobals;
struct RawFile;
struct LeaderboardDef;
struct XGlobals;
struct Glasses;
struct EmblemSet;
struct ScriptParseTree;
struct KeyValuePairs;
struct MemoryBlock;
struct AddonMapEnts;
struct SkinnedVertsDef;
struct Qdb;
struct Slug;
struct FootstepTableDef;
struct FootstepFXTableDef;
union XAssetHeader;
struct WeaponVariantDefHash;
struct BulletFireParams;
struct VehicleState;
struct itemInfo_t;
struct segment;
struct challengeTableRow_t;
struct viewLerpWaypoint_s;
struct MantleResults;
struct animStringItem_t;
struct IPakLoadedPackfile;
struct IPakIndexEntry;
struct IPakWorkData;
struct NetFieldList;
struct demoTaggedPlayers;
struct demoDefaultBookmark;
struct demoFooter;
struct demoSnapshotData;
struct demoMemBlock;
struct uiInfo_s;
struct qtime_s;
struct WorkerCmdConditional;
struct clientDebugStringInfo_t;
struct clientDebugLineInfo_t;
struct clientDebugSphereInfo_t;
struct AnimState;
struct AnimStateDef;
struct FxBeam;
struct ShardGroup;
struct Allocator;
struct GlassUpdateCmd;
struct trStatistics_t;
struct GfxLodParms;
struct r_double_index_t;
struct DiskGfxVertex;
struct qosPayload_t;
struct fileRetryInfo;
struct z_stream_s;
struct ct_data_s;
struct tree_desc_s;
struct XZoneInfo;
struct persistentStats;
struct dwFileShareListTask;
struct dwFileShareRemoveTask;
struct dwFileShareSummaryTask;
struct GSPolicyResponse_t;
struct _EXCEPTION_POINTERS;
struct statsDelta_t;
struct SndPlayback;
struct SndSpeakerMap;
struct SndCommand;
struct orientation_t;
struct SndNotify;
struct SndFader;
struct SndDuckActive;
struct SndListener;
struct PlayerSkill;
union ddlValue_t;
struct dwTeamClanLeaveTask;
struct jsmn_parser;
struct jsmntok_t;
struct SndRvParams;
struct snd_occlusion_multiple;
struct SndDspBiQuadCoef;
struct sd_voice_param;
struct sd_voice;
struct sd_mix_master_param;
struct SndStartAliasInfo;
struct SndOverlayInfo;
struct sentient_fields_s;
struct PathBlockPlanes;
struct pathsort_t;
struct sightclip_t;
struct pathnode_parent_t;
struct badplace_arc_t;
struct scr_entref_t;
struct RadiantCommand;
struct PotentialTargetData;
struct team_move_other_context_t;
struct team_move_context_t;
struct sentient_sort_t;
struct actor_fields_s;
union badplace_parms_t;
struct badplace_t;
struct weaponParms;
struct checkStopParams_t;
struct PhysicsInputs;
union sval_u;
struct scr_block_s;
struct yy_buffer_state;
struct debugFileInfo_t;
struct objFileInfo_t;
struct ScriptExpression_t;
struct _watchNode_t;
struct flameGeneric_s;
struct flameStream_s;
struct flameChunk_s;
struct flameDrips_t;
struct flameFire_t;
struct flameWeaponConfig_t;
struct IKSystem;
struct localEntity_s;
struct Bone;
struct BoneOrientation;
struct RagdollBody;
struct BoneDef;
struct JointDef;
struct XDollBone;
struct XDollBoneOrientation;
struct XDoll_ConstraintInfo;
struct XDollBody;
struct leafList_s;
struct GfxVertex;
struct debug_patch_info_t;
struct chull_t;
struct GfxPointVertex;
struct auto_rigid_body;
struct DObjTrace_s;
struct collision_material_t;
struct SimplePlaneIntersection;
struct XModelConfig;
struct XModelPartsLoad;
struct XSurfaceGetTriCandidatesLocals;
struct ClientNotifyData;
struct XAnimServerNotifyList;
struct XModelNameMap;
struct physBatch;
struct tagPOINT;
struct _DM_CMDCONT;
struct _TOKEN_PRIVILEGES;
struct sysEvent_t;
struct _XINPUT_GAMEPAD;
struct GamePad;
struct winDmCommand;
struct AudioState;
struct TIAState;
struct Machine;
struct NTPMessage;
struct reliableClient;
struct PhysicalMemoryPrim;
struct PhysicalMemory;
struct HunkUserNull;
struct EvalValue;
union PackedLmapCoords;
struct iwd_t;
struct searchpath_s;
struct OperandList;
struct OperandStack;
struct pc_token_s;
struct expressionEntry;
struct ExpressionAllocState;
struct bb_msg_t;
struct GfxUI3DStack;
struct nestingStack_t;
struct votingHandler_t;
struct codtvDWContent_t;
struct codtvFolder_t;
struct sightpointtrace_t;
struct statmonitor_s;
struct Block;
struct SaveHeader;
struct nodetype;
struct huff_t;
struct huffman_t;
struct streamInfo;
struct PathItem;
struct callbackInfo;
struct PacketQueueBlock;
struct PacketQueue;
struct meminfo_t;
struct field_t;
struct MapProfileEntry;
struct MapProfileElement;
struct MapProfileHotSpot;
struct areaParms_t;
struct winding_t;
struct dwTwitchRegisterTask;
struct League;
struct LeagueDivision;
struct LeagueTeam;
struct audioSample_t;
struct useList_t;
struct GamerProfileBuffer;
struct antilagActorStore_t;
struct antilagVehicleStore_t;
struct ipFilter_s;
struct SpawnPoint;
struct SpawnInfluencer;
struct game_hudelem_s;
union statValue_t;
struct saveField_t;
struct game_hudelem_field_t;
struct bot_threat_t;
struct client_fields_s;
struct vehicle_fields_s;
struct EntHandleList;
struct Avoid;
struct OrcaPlane;
struct FxCurve;
struct FxCurveIterator;
struct FxCamera;
struct FxSpatialFrame;
struct FxEffect;
struct FxElem;
struct FxTrail;
struct FxTrailElem;
struct FxUniqueHandleDb;
struct FxPointGroup;
struct FxMarksGridCell;
struct FxTriGroup;
struct FxMarksSystem;
struct FxCameraUpdate;
struct FxSpawnEffectCmd;
struct FxSystemBuffers;
struct FxSprite;
struct FxPostLight;
struct FxPostLightInfo;
struct EffectElementDraw;
struct FxElemPreVisualState;
struct FxColor4b;
struct FxGenerateVertsCmd;
struct FxProfileEntry;
struct GfxConfiguration;
struct GfxWorldVertex;
struct FxMarkTri;
struct MarkInfo;
struct FxEditorElemDef;
struct FxEditorEffectDef;
struct FxFlagOutputSet;
struct FxElemSetupCmd;
struct FxDrawSpriteGeoCmd;
struct FxDrawTrailGeoCmd;
struct DynEntityConstraintCreateParams;
struct DevMenuItem;
struct XAsset;
struct XBlock;
struct XAssetEntry;
struct XZone;
struct DBReorderAssetEntry;
struct ShaderStats;
struct DBDecompressCmd_t;
struct peerResults_t;
struct PartyField;
struct MessageLine;
struct Message;
struct MessageWindow;
struct GfxExtraCamParms;
struct kbutton_t;
struct CEntityAreaParms;
struct snd_weapon_shot;
struct WeaponOptions;
struct cent_field_t;
struct dynent_field_s;
struct cent_field_s;
struct soundRandom_t;
struct _lightModel_t;
struct _mixerLight_t;
struct RumbleGraph;
struct RumbleInfo;
struct ActiveRumble;
struct CG_PerfData;
struct cg_hudelem_t;
struct DelayListInfo;
struct EffectFile;
struct RopeGenerateVertsCmd;
struct CompassActor;
struct CameraShake;
struct punctuation_s;
struct define_s;
struct source_s;
struct AimTarget;
struct GfxDelayedCmdBuf;
struct GfxBspDrawSurfData;
struct GfxSModelDrawSurfData;
struct mnode_load_t;
struct GfxBspLoad;
struct GfxStaticModelCombinedInst;
struct DiskTriangleSoup;
struct CinematicInfo;
struct CinematicTextureSet;
struct GfxCachedShaderText;
struct GfxAssembledShaderText;
struct GfxModelSkinnedSurface;
struct XModelRigidCullInfoContext;
struct DpvsDynamicCellCmd;
struct DpvsPlanes;
struct DpvsClipPlanes;
struct GfxCmdBufContext;
struct GfxTrianglesDrawStream;
struct PerfTimerStyle;
struct PerfTimerFrameHistory;
struct GPUTimerFrame;
struct ImageList;
struct GfxImageFileHeader;
struct PerMapMaterialTable;
struct stream_source_info_t;
struct ScriptableConstant;
struct MtlStateMapBitName;
struct MaterialStateMapRule;
struct MaterialStateMap;
struct _D3D11_SIGNATURE_PARAMETER_DESC;
struct ShaderArgumentSource;
struct VertexConstantMappingEntry;
struct GfxDecodedLightGridColors;
struct GfxShadowedLightHistory;
struct GfxCmdDrawPoints;
struct GfxSceneParms;
struct GfxDrawSurfListArgs;
struct GfxRenderCommandExecState;
struct Corona;
struct CoronaState;
struct OcclusionQuery;

struct MenuCell
{
  int type;
  int maxChars;
  char *stringValue;
};

union vec4_t
{
  float v[4];
  $91D1B2149FAC90180ECB9AC277F76009 __s1;
  $43F634250C0E94E2A09AB0840E4770D1 __s2;
};

union DvarValue
{
  bool enabled;
  int integer;
  unsigned int unsignedInt;
  __int64 integer64;
  unsigned __int64 unsignedInt64;
  float value;
  vec4_t vector;
  const char *string;
  unsigned __int8 color[4];
};

union DvarLimits
{
  DvarLimits::<unnamed_type_enumeration> enumeration;
  DvarLimits::<unnamed_type_integer> integer;
  DvarLimits::<unnamed_type_integer64> integer64;
  DvarLimits::<unnamed_type_value> value;
  DvarLimits::<unnamed_type_vector> vector;
};

union vec3_t
{
  $393C16A032292777F0C3725FFB2C0008 __s0;
  float v[3];
};

struct cplane_s
{
  vec3_t normal;
  float dist;
  unsigned __int8 type;
  unsigned __int8 signbits;
  unsigned __int8 pad[2];
};

union GfxDrawSurf
{
  GfxDrawSurfFields fields;
  unsigned __int64 packed;
};

struct MaterialStreamRouting
{
  unsigned __int8 source;
  unsigned __int8 dest;
};

struct D3D11_MAPPED_SUBRESOURCE
{
  void *pData;
  unsigned int RowPitch;
  unsigned int DepthPitch;
};

struct MaterialVertexDeclaration
{
  unsigned __int8 streamCount;
  bool hasOptionalSource;
  bool isLoaded;
  MaterialVertexStreamRouting routing;
};

struct GfxVertexShaderLoadDef
{
  unsigned __int8 *program;
  unsigned int programSize;
};

struct MaterialVertexShader
{
  const char *name;
  MaterialVertexShaderProgram prog;
};

struct GfxPixelShaderLoadDef
{
  unsigned __int8 *program;
  unsigned int programSize;
};

struct MaterialPixelShader
{
  const char *name;
  MaterialPixelShaderProgram prog;
};

struct MaterialShaderArgument
{
  unsigned __int16 type;
  MaterialArgumentLocation location;
  unsigned __int16 size;
  unsigned __int16 buffer;
  MaterialArgumentDef u;
};

struct MaterialPass
{
  MaterialVertexDeclaration *vertexDecl;
  MaterialVertexShader *vertexShader;
  $77EECB44B199C2EB4EDE6B9029E80D61 ___u2;
  unsigned __int8 perPrimArgCount;
  unsigned __int8 perObjArgCount;
  unsigned __int8 stableArgCount;
  unsigned __int8 customSamplerFlags;
  unsigned __int8 precompiledIndex;
  unsigned __int8 materialType;
  $1117502D9463626EB1EBD975BD01E3D7 ___u9;
};

struct MaterialTechnique
{
  const char *name;
  unsigned __int16 flags;
  unsigned __int16 passCount;
  MaterialPass passArray[1];
};

struct MaterialTechniqueSet
{
  const char *name;
  unsigned __int8 worldVertFormat;
  MaterialTechnique *techniques[36];
};

struct Picmip
{
  unsigned __int8 platform[2];
};

struct GfxImage
{
  GfxTexture texture;
  unsigned __int8 mapType;
  unsigned __int8 semantic;
  unsigned __int8 category;
  bool delayLoadPixels;
  Picmip picmip;
  bool noPicmip;
  unsigned __int8 track;
  CardMemory cardMemory;
  unsigned __int16 width;
  unsigned __int16 height;
  unsigned __int16 depth;
  unsigned __int8 levelCount;
  unsigned __int8 streaming;
  unsigned int baseSize;
  unsigned __int8 *pixels;
  GfxStreamedPartInfo streamedParts[1];
  unsigned __int8 streamedPartCount;
  unsigned int loadedSize;
  unsigned __int8 skippedMipLevels;
  const char *name;
  unsigned int hash;
};

struct GfxStateBits
{
  unsigned int loadBits[2];
  ID3D11BlendState *blendState;
  ID3D11DepthStencilState *depthStencilState;
  ID3D11RasterizerState *rasterizerState;
};

struct Material
{
  MaterialInfo info;
  unsigned __int8 stateBitsEntry[36];
  unsigned __int8 textureCount;
  unsigned __int8 constantCount;
  unsigned __int8 stateBitsCount;
  unsigned __int8 stateFlags;
  unsigned __int8 cameraRegion;
  unsigned __int8 probeMipBits;
  $BCB88418F21235C26DC4B3F0337E3398 ___u8;
  MaterialTextureDef *textureTable;
  $6A288F01A0821CDAFC2CA40E2BA7B27F ___u10;
  GfxStateBits *stateBitsTable;
  Material *thermalMaterial;
};

struct PhysConstraint
{
  unsigned __int16 targetname;
  ConstraintType type;
  AttachPointType attach_point_type1;
  int target_index1;
  unsigned __int16 target_ent1;
  const char *target_bone1;
  AttachPointType attach_point_type2;
  int target_index2;
  unsigned __int16 target_ent2;
  const char *target_bone2;
  vec3_t offset;
  vec3_t pos;
  vec3_t pos2;
  vec3_t dir;
  int flags;
  int timeout;
  int min_health;
  int max_health;
  float distance;
  float damp;
  float power;
  vec3_t scale;
  float spin_scale;
  float minAngle;
  float maxAngle;
  Material *material;
  int constraintHandle;
  int rope_index;
  int centity_num[4];
};

struct XNADDR
{
  unsigned __int8 addrBuff[37];
};

union hudelem_color_t
{
  $0D0CB43DF22755AD856C77DD3F304010 __s0;
  int rgba;
};

struct Operand
{
  expDataType dataType;
  operandInternalDataUnion internals;
};

struct Font_s
{
  const char *fontName;
  int pixelHeight;
  int isScalingAllowed;
  int glyphCount;
  int kerningPairsCount;
  Material *material;
  Material *glowMaterial;
  Glyph *glyphs;
  KerningPairs *kerningPairs;
};

struct rectDef_s
{
  float x;
  float y;
  float w;
  float h;
  int horzAlign;
  int vertAlign;
};

struct PhysConstraints
{
  const char *name;
  unsigned int count;
  PhysConstraint data[16];
};

struct listBoxDef_s
{
  int mousePos;
  int cursorPos[1];
  int startPos[1];
  int endPos[1];
  int drawPadding;
  float elementWidth;
  float elementHeight;
  int numColumns;
  float special;
  columnInfo_s columnInfo[16];
  int notselectable;
  int noScrollBars;
  int usePaging;
  vec4_t selectBorder;
  vec4_t disableColor;
  vec4_t focusColor;
  vec4_t elementHighlightColor;
  vec4_t elementBackgroundColor;
  Material *selectIcon;
  Material *backgroundItemListbox;
  Material *highlightTexture;
  int noBlinkingHighlight;
  MenuRow *rows;
  int maxRows;
  int rowCount;
};

struct ExpressionStatement
{
  char *filename;
  int line;
  int numRpn;
  expressionRpn *rpn;
};

struct GenericEventScript
{
  ScriptCondition *prerequisites;
  ExpressionStatement condition;
  int type;
  bool fireOnTrue;
  const char *action;
  int blockID;
  int constructID;
  GenericEventScript *next;
};

struct animParamsDef_t
{
  const char *name;
  rectDef_s rectClient;
  float borderSize;
  vec4_t foreColor;
  vec4_t backColor;
  vec4_t borderColor;
  vec4_t outlineColor;
  float textScale;
  float rotation;
  GenericEventHandler *onEvent;
};

struct HunkUser
{
  HU_ALLOCATION_SCHEME scheme;
  unsigned int flags;
  const char *name;
  int type;
};

struct PhysPreset
{
  const char *name;
  int flags;
  float mass;
  float bounce;
  float friction;
  float bulletForceScale;
  float explosiveForceScale;
  const char *sndAliasPrefix;
  float piecesSpreadFraction;
  float piecesUpwardVelocity;
  int canFloat;
  float gravityScale;
  vec3_t centerOfMassOffset;
  vec3_t buoyancyBoxMin;
  vec3_t buoyancyBoxMax;
};

union Weapon
{
  $190F2CF944EC18EE3AF27F473C4F9DBE __s0;
  unsigned int weaponData;
};

struct PhysGeomInfo
{
  BrushWrapper *brush;
  int type;
  vec3_t orientation[3];
  vec3_t offset;
  vec3_t halfLengths;
};

struct SndAlias
{
  const char *name;
  unsigned int id;
  const char *subtitle;
  const char *secondaryname;
  unsigned int assetId;
  const char *assetFileName;
  unsigned int flags0;
  unsigned int flags1;
  unsigned int duck;
  unsigned int contextType;
  unsigned int contextValue;
  unsigned int stopOnPlay;
  unsigned int futzPatch;
  unsigned __int16 fluxTime;
  unsigned __int16 startDelay;
  unsigned __int16 reverbSend;
  unsigned __int16 centerSend;
  unsigned __int16 volMin;
  unsigned __int16 volMax;
  unsigned __int16 pitchMin;
  unsigned __int16 pitchMax;
  unsigned __int16 distMin;
  unsigned __int16 distMax;
  unsigned __int16 distReverbMax;
  unsigned __int16 envelopMin;
  unsigned __int16 envelopMax;
  unsigned __int16 envelopPercentage;
  __int16 fadeIn;
  __int16 fadeOut;
  __int16 dopplerScale;
  unsigned __int8 minPriorityThreshold;
  unsigned __int8 maxPriorityThreshold;
  unsigned __int8 probability;
  unsigned __int8 occlusionLevel;
  unsigned __int8 minPriority;
  unsigned __int8 maxPriority;
  unsigned __int8 pan;
  unsigned __int8 limitCount;
  unsigned __int8 entityLimitCount;
  unsigned __int8 duckGroup;
};

struct SndAliasList
{
  const char *name;
  unsigned int id;
  SndAlias *head;
  int count;
  int sequence;
};

union VariableUnion
{
  int intValue;
  unsigned int uintValue;
  float floatValue;
  unsigned int stringValue;
  const float *vectorValue;
  unsigned __int8 *codePosValue;
  unsigned int pointerValue;
  VariableStackBuffer *stackValue;
  unsigned int entityOffset;
};

struct ChildVariableValue
{
  ChildVariableValue::<unnamed_type_u> u;
  unsigned __int16 next;
  unsigned __int8 type;
  unsigned __int8 name_lo;
  ChildBucketMatchKeys k;
  unsigned __int16 nextSibling;
  unsigned __int16 prevSibling;
};

struct LeagueStats
{
  int rankPoints;
  int rank;
  float floats[3];
  int ints[8];
};

struct netProfileStream_t
{
  netProfilePacket_t packets[60];
  int iCurrPacket;
  int iBytesPerSecond;
  int iLastBPSCalcTime;
  int iCountedPackets;
  int iCountedFragments;
  int iFragmentPercentage;
  int iLargestPacket;
  int iSmallestPacket;
};

struct PhysGeomList
{
  unsigned int count;
  PhysGeomInfo *geoms;
  int contents;
};

struct windowDef_t
{
  const char *name;
  rectDef_s rect;
  rectDef_s rectClient;
  const char *group;
  unsigned __int8 style;
  unsigned __int8 border;
  unsigned __int8 modal;
  unsigned __int8 frameSides;
  float frameTexSize;
  float frameSize;
  int ownerDraw;
  int ownerDrawFlags;
  float borderSize;
  int staticFlags;
  int dynamicFlags[1];
  int nextTime;
  vec4_t foreColor;
  vec4_t backColor;
  vec4_t borderColor;
  vec4_t outlineColor;
  float rotation;
  Material *background;
};

union vec2_t
{
  float v[2];
  $38C3DEC81229B66F67FB6D350D75FF5A __s1;
};

struct textDef_s
{
  rectDef_s textRect[1];
  int alignment;
  int fontEnum;
  int itemFlags;
  int textAlignMode;
  float textalignx;
  float textaligny;
  float textscale;
  float textpadding;
  int textStyle;
  vec4_t fontColor;
  vec4_t glowColor;
  vec4_t shadowColor;
  float fontBlur;
  float glowSize;
  float shadowSize;
  vec2_t shadowOffset;
  const char *text;
  textExp_s *textExpData;
  textDefData_t textTypeData;
};

struct UILocalVar
{
  UILocalVarType type;
  const char *name;
  UILocalVar::<unnamed_type_u> u;
};

struct UILocalVarContext
{
  UILocalVar table[256];
};

union SndEntHandle
{
  SndEntHandle::<unnamed_type_field> field;
  int handle;
};

union __m128
{
  float m128_f32[4];
  unsigned __int64 m128_u64[2];
  char m128_i8[16];
  __int16 m128_i16[8];
  int m128_i32[4];
  __int64 m128_i64[2];
  unsigned __int8 m128_u8[16];
  unsigned __int16 m128_u16[8];
  unsigned int m128_u32[4];
};

struct __m128d
{
  long double m128d_f64[2];
};

struct sockaddr
{
  unsigned __int16 sa_family;
  char sa_data[14];
};

struct LeagueOutcomes
{
  LeagueStats base;
  LeagueStats winner;
  LeagueStats loser;
};

struct ddlEnumDef_t
{
  const char *name;
  int memberCount;
  const char **members;
  ddlHash_t *hashTable;
};

struct LerpEntityStateDestructibleHit
{
  unsigned int modelState[3];
};

struct renderOptions_s
{
  unsigned int s;
};

struct MantleState
{
  float yaw;
  int timer;
  int transIndex;
  int flags;
};

struct TracerDef
{
  const char *name;
  tracerType_t type;
  Material *material;
  unsigned int drawInterval;
  float speed;
  float beamLength;
  float beamWidth;
  float screwRadius;
  float screwDist;
  float fadeTime;
  float fadeScale;
  float texRepeatRate;
  vec4_t colors[5];
};

struct SubpartyInfo
{
  SubpartyMember members[18];
  bool links[18];
  int count;
  float skill;
  int skillRanking;
  int searchStartUTC;
  int score;
  int team;
};

struct score_s
{
  int ping;
  int status_icon;
  int place;
  int score;
  int kills;
  int assists;
  int deaths;
  int wagerWinnings;
  int scoreboardColumns[5];
  int downs;
  int revives;
  int headshots;
  int scoreMultiplier;
  int currentStreak;
};

struct VariableValue
{
  $95275E6A03F17B41529199DA58246C8A ___u0;
};

struct EntHandle
{
  unsigned __int16 number;
  unsigned __int16 infoIndex;
};

struct MemoryFile
{
  unsigned __int8 *buffer;
  int bufferSize;
  int bytesUsed;
  unsigned __int8 *careerStatsBuffer;
  int cacheBufferUsed;
  int segmentIndex;
  int segmentStart;
  int nonZeroCount;
  int zeroCount;
  bool errorOnOverflow;
  bool memoryOverflow;
  bool compress_enabled;
  bool rle_enabled;
  bool is_writing;
  int cacheBufferAvail;
  unsigned __int8 cacheBuffer[32760];
};

struct mover_positions_t
{
  float decelTime;
  float speed;
  float midTime;
  vec3_t pos1;
  vec3_t pos2;
  vec3_t pos3;
};

struct svEntity_s
{
  unsigned __int16 worldSector;
  unsigned __int16 nextEntityInWorldSector;
  int linkcontents;
  vec3_t linkmin;
  vec3_t linkmax;
};

struct WeaponAttachment
{
  const char *szInternalName;
  const char *szDisplayName;
  eAttachment attachmentType;
  eAttachmentPoint attachmentPoint;
  PenetrateType penetrateType;
  weapFireType_t fireType;
  int firstRaisePriority;
  float fHipIdleAmount;
  bool bAltWeaponAdsOnly;
  bool bAltWeaponDisableSwitching;
  float altScopeADSTransInTime;
  float altScopeADSTransOutTime;
  bool bSilenced;
  bool bDualMag;
  bool laserSight;
  bool bInfraRed;
  bool bUseAsMelee;
  bool bDualWield;
  bool sharedAmmo;
  float fDamageRangeScale;
  float fAdsZoomFov1;
  float fAdsZoomFov2;
  float fAdsZoomFov3;
  float fAdsZoomInFrac;
  float fAdsZoomOutFrac;
  float fAdsTransInTimeScale;
  float fAdsTransOutTimeScale;
  float fAdsRecoilReductionRate;
  float fAdsRecoilReductionLimit;
  float fAdsViewKickCenterSpeedScale;
  float fAdsIdleAmountScale;
  bool swayOverride;
  float swayMaxAngle;
  float swayLerpSpeed;
  float swayPitchScale;
  float swayYawScale;
  float swayHorizScale;
  float swayVertScale;
  bool adsSwayOverride;
  float adsSwayMaxAngle;
  float adsSwayLerpSpeed;
  float adsSwayPitchScale;
  float adsSwayYawScale;
  float fAdsSwayHorizScale;
  float fAdsSwayVertScale;
  float adsMoveSpeedScale;
  float fHipSpreadMinScale;
  float fHipSpreadMaxScale;
  float strafeRotR;
  float standMoveF;
  vec3_t vStandRot;
  float fFireTimeScale;
  float fReloadTimeScale;
  float fReloadEmptyTimeScale;
  float fReloadAddTimeScale;
  float fReloadQuickTimeScale;
  float fReloadQuickEmptyTimeScale;
  float fReloadQuickAddTimeScale;
  bool mmsWeapon;
  bool mmsInScope;
  float mmsFOV;
  float mmsAspect;
  float mmsMaxDist;
  float clipSizeScale;
  int iClipSize;
  unsigned int stackFire;
  float stackFireSpread;
  float stackFireAccuracyDecay;
  unsigned int perks[2];
  float customFloat0;
  float customFloat1;
  float customFloat2;
  int customBool0;
  int customBool1;
  int customBool2;
};

struct clSnapshot_t
{
  int valid;
  int snapFlags;
  int serverTime;
  int physicsTime;
  int messageNum;
  int deltaNum;
  int ping;
  int cmdNum;
  playerState_s ps;
  int numEntities;
  int numClients;
  int numActors;
  int parseMatchStateIndex;
  int parseEntitiesIndex;
  int parseClientsIndex;
  int parseActorsIndex;
  int serverCommandNum;
};

struct trajectory_t
{
  unsigned __int8 trType;
  int trTime;
  int trDuration;
  vec3_t trBase;
  vec3_t trDelta;
};

struct viewClampState
{
  viewClamp min;
  viewClamp max;
  float accelTime;
  float decelTime;
  float totalTime;
  float startTime;
};

struct ai_orient_t
{
  ai_orient_mode_t eMode;
  float fDesiredLookPitch;
  float fDesiredLookYaw;
  float fDesiredBodyYaw;
};

struct actor_prone_info_s
{
  bool bCorpseOrientation;
  bool orientPitch;
  bool prone;
  int iProneTime;
  int iProneTrans;
  float fBodyHeight;
  $A899A4A44C693354E5CF33C9EDFF92AE ___u6;
  $8F7A1F2A0E788339D3BE9A175DA5EAEF ___u7;
};

struct pathpoint_t
{
  vec3_t vOrigPoint;
  vec2_t fDir2D;
  float fOrigLength;
  int iNodeNum;
};

struct path_t
{
  pathpoint_t pts[32];
  __int16 wPathLen;
  __int16 wOrigPathLen;
  __int16 wDodgeCount;
  __int16 wNegotiationStartNode;
  __int16 lookaheadNextNode;
  __int16 pathChangeNotifyNode;
  __int16 wDodgeEntity;
  vec3_t vFinalGoal;
  vec3_t vStartPos;
  vec3_t lookaheadDir;
  vec3_t lookaheadPos;
  float fLookaheadDist;
  float fLookaheadAmount;
  float fLookaheadDistToNextNode;
  int minLookAheadNodes;
  int flags;
  int iPathTime;
  int iPathClearedTime;
  team_t eTeam;
  float fCurrLength;
  vec3_t vCurrPoint;
  int iPathEndTime;
  float pathEndAnimDistSq;
  bool pathEndAnimNotified;
  bool lookaheadHitsStairs;
  bool useChokePoints;
  vec2_t pathChangeTracePos;
  int randomPercent;
  int owner;
  float physRadius;
  float physHeight;
};

struct path_trim_t
{
  int iIndex;
  int iDelta;
};

struct potential_threat_t
{
  bool isEnabled;
  vec2_t direction;
};

struct SentientHandle
{
  unsigned __int16 number;
  unsigned __int16 infoIndex;
};

struct actor_goal_s
{
  vec3_t pos;
  vec3_t ang;
  float radius;
  float height;
  pathnode_t *node;
  gentity_t *volume;
};

struct vis_cache_t
{
  bool bVisible;
  int iLastUpdateTime;
  int iLastVisTime;
};

struct col_prim_t
{
  int type;
  $FC3A6267FE0F5339E010A222FD8EA39F ___u1;
};

struct gentity_t
{
  entityState_s s;
  entityShared_t r;
  gclient_t *client;
  actor_t *actor;
  sentient_t *sentient;
  TurretInfo *pTurretInfo;
  Destructible *destructible;
  vehicle_t *vehicle;
  unsigned __int16 model;
  unsigned __int8 physicsObject;
  unsigned __int8 takedamage;
  unsigned __int8 active;
  unsigned __int8 nopickup;
  unsigned __int8 handler;
  unsigned __int8 team;
  unsigned __int8 avoidHandle;
  unsigned __int16 classname;
  unsigned __int16 target;
  unsigned __int16 targetname;
  unsigned __int16 script_noteworthy;
  unsigned int attachIgnoreCollision;
  int spawnflags;
  int flags;
  int eventTime;
  int freeAfterEvent;
  int unlinkAfterEvent;
  int clipmask;
  int processedFrame;
  EntHandle parent;
  int nextthink;
  int health;
  int maxHealth;
  int damage;
  flame_timed_damage_t flame_timed_damage[4];
  int last_timed_radius_damage;
  int count;
  $1E130839BD907190999A544F8C59A266 ___u36;
  EntHandle missileTargetEnt;
  gentity_t::<unnamed_type_snd_wait> snd_wait;
  tagInfo_t *tagInfo;
  gentity_t *tagChildren;
  unsigned __int16 attachModelNames[19];
  unsigned __int16 attachTagNames[19];
  XAnimTree_s *pAnimTree;
  unsigned __int16 disconnectedLinks;
  int iDisconnectTime;
  int useCount;
  int physObjId;
  gentity_t *nextFree;
  int birthTime;
  int ikPlayerclipTerrainTime;
  int ikDisableTerrainMappingTime;
};

struct pathnode_t
{
  pathnode_constant_t constant;
  pathnode_dynamic_t dynamic;
  pathnode_transient_t transient;
};

struct TurretInfo
{
  bool inuse;
  int state;
  int flags;
  int fireTime;
  EntHandle manualTarget;
  EntHandle target;
  vec3_t targetPos;
  int targetTime;
  vec3_t missOffsetNormalized;
  float arcmin[2];
  float arcmax[2];
  float initialYawmin;
  float initialYawmax;
  float forwardAngleDot;
  float dropPitch;
  float scanningPitch;
  int convergenceTime[2];
  int suppressTime;
  float maxRangeSquared;
  SentientHandle detachSentient;
  int stance;
  int prevStance;
  int fireSndDelay;
  float accuracy;
  vec3_t userOrigin;
  int prevSentTarget;
  float aiSpread;
  float playerSpread;
  team_t eTeam;
  float heatVal;
  bool overheating;
  int fireBarrel;
  float scanSpeed;
  float scanDecelYaw;
  int scanPauseTime;
  vec3_t originError;
  vec3_t anglesError;
  float pitchCap;
  int triggerDown;
  unsigned int fireSnd;
  unsigned int fireSndPlayer;
  unsigned int startFireSnd;
  unsigned int startFireSndPlayer;
  unsigned int loopFireEnd;
  unsigned int loopFireEndPlayer;
  unsigned int rotateLoopSnd;
  unsigned int rotateLoopSndPlayer;
  unsigned int rotateStopSnd;
  unsigned int rotateStopSndPlayer;
  int sndIsFiring;
  vec3_t targetOffset;
  float onTargetAngle;
  TurretRotateState turretRotateState;
  vec3_t previousAngles;
};

struct DObjAnimMat
{
  vec4_t quat;
  vec3_t trans;
  float transWeight;
};

struct XSurfaceVertexInfo
{
  __int16 vertCount[4];
  unsigned __int16 *vertsBlend;
  float *tensionData;
};

union GfxColor
{
  unsigned int packed;
  unsigned __int8 array[4];
};

union PackedTexCoords
{
  unsigned int packed;
};

union PackedUnitVec
{
  unsigned int packed;
};

struct GfxPackedVertex
{
  vec3_t xyz;
  float binormalSign;
  GfxColor color;
  PackedTexCoords texCoord;
  PackedUnitVec normal;
  PackedUnitVec tangent;
};

struct XModel
{
  const char *name;
  unsigned __int8 numBones;
  unsigned __int8 numRootBones;
  unsigned __int8 numsurfs;
  unsigned __int8 lodRampType;
  $C8C573B57ACA1D7542AD56C4163862EC ___u5;
  $37E13A30061EC97EDA76440B3BA5E97A ___u6;
  $BF9640C0B3AB5E078C286DD9616EC22F ___u7;
  $E1CD6A013C1D28F2956F4983A8D1052C ___u8;
  unsigned __int8 *partClassification;
  DObjAnimMat *baseMat;
  XSurface *surfs;
  Material **materialHandles;
  XModelLodInfo lodInfo[4];
  XModelCollSurf_s *collSurfs;
  int numCollSurfs;
  int contents;
  $D4353AFCDE5CB0AE04F2D0880C27B026 ___u17;
  float radius;
  vec3_t mins;
  vec3_t maxs;
  __int16 numLods;
  __int16 collLod;
  float *himipInvSqRadii;
  int memUsage;
  int flags;
  bool bad;
  PhysPreset *physPreset;
  unsigned __int8 numCollmaps;
  Collmap *collmaps;
  PhysConstraints *physConstraints;
  vec3_t lightingOriginOffset;
  float lightingOriginRange;
};

struct FxFloatRange
{
  float base;
  float amplitude;
};

struct FxElemMarkVisuals
{
  Material *materials[2];
};

struct GfxLightDef
{
  const char *name;
  GfxLightImage attenuation;
  int lmapLookupStart;
};

union FxElemVisuals
{
  const void *anonymous;
  Material *material;
  XModel *model;
  FxEffectDefRef effectDef;
  const char *soundName;
  GfxLightDef *lightDef;
};

struct FxTrailDef
{
  int scrollTimeMsec;
  int repeatDist;
  int splitDist;
  int vertCount;
  $6F757D3FECE1EA491BD8B6C97BF0CB9E ___u4;
  int indCount;
  $D31B43AE1E46D24CA4A859818848B5E1 ___u6;
};

struct DestructiblePiece
{
  DestructibleStage stages[5];
  unsigned __int8 parentPiece;
  float parentDamagePercent;
  float bulletDamageScale;
  float explosiveDamageScale;
  float meleeDamageScale;
  float impactDamageScale;
  float entityDamageTransfer;
  PhysConstraints *physConstraints;
  int health;
  const char *damageSound;
  const FxEffectDef *burnEffect;
  const char *burnSound;
  unsigned __int16 enableLabel;
  int hideBones[5];
};

struct DestructibleDef
{
  const char *name;
  XModel *model;
  XModel *pristineModel;
  int numPieces;
  DestructiblePiece *pieces;
  int clientOnly;
};

struct DestructibleState
{
  LerpEntityStateDestructibleHit state;
  int time;
};

struct vehicle_node_t
{
  unsigned __int16 name;
  unsigned __int16 target;
  unsigned __int16 target2;
  unsigned __int16 script_linkname;
  unsigned __int16 script_noteworthy;
  __int16 index;
  int flags;
  float speed;
  float lookAhead;
  vec3_t origin;
  vec3_t angles;
  float radius;
  float tension;
  $932BC442CFCBD9C3DAA28EDA9FBF6948 ___u13;
};

struct vehicle_physic_t
{
  vec3_t origin;
  vec3_t prevOrigin;
  vec3_t angles;
  vec3_t prevAngles;
  vec3_t maxAngleVel;
  float yawAccel;
  float yawDecel;
  vec3_t mins;
  vec3_t maxs;
  vec3_t vel;
  vec3_t bodyVel;
  vec3_t rotVel;
  vec3_t accel;
  float maxPitchAngle;
  float maxRollAngle;
  float wheelZVel[6];
  float wheelZPos[6];
  int wheelSurfType[6];
  vec3_t bodyTilt;
  vec3_t worldTilt;
  vec3_t worldTiltVel;
  float heliLockHeight;
  float curveLength;
  int curveID;
  float curveStep;
  float curveTime;
  float timeStep;
};

struct VehicleJitter
{
  int jitterPeriodMin;
  int jitterPeriodMax;
  int jitterEndTime;
  vec3_t jitterOffsetRange;
  vec3_t jitterDeltaAccel;
  vec3_t jitterAccel;
  vec3_t jitterPos;
};

struct GraphFloat
{
  char name[64];
  vec2_t knots[32];
  int knotCount;
  float scale;
  DevGraph devguiGraph;
};

struct cLeafBrushNode_s
{
  unsigned __int8 axis;
  __int16 leafBrushCount;
  int contents;
  cLeafBrushNodeData_t data;
};

struct ClipInfo
{
  int planeCount;
  cplane_s *planes;
  unsigned int numMaterials;
  ClipMaterial *materials;
  unsigned int numBrushSides;
  cbrushside_t *brushsides;
  unsigned int leafbrushNodesCount;
  cLeafBrushNode_s *leafbrushNodes;
  unsigned int numLeafBrushes;
  unsigned __int16 *leafbrushes;
  unsigned int numBrushVerts;
  vec3_t *brushVerts;
  unsigned int nuinds;
  unsigned __int16 *uinds;
  unsigned __int16 numBrushes;
  cbrush_t *brushes;
  Bounds *brushBounds;
  int *brushContents;
};

struct cmodel_t
{
  vec3_t mins;
  vec3_t maxs;
  float radius;
  ClipInfo *info;
  cLeaf_s leaf;
};

struct TraceThreadInfo
{
  TraceCheckCount checkcount;
  cbrush_t *box_brush;
  cmodel_t *box_model;
  PhysGeomList **geoms;
};

struct XAnimDeltaPart
{
  XAnimPartTrans *trans;
  XAnimDeltaPartQuat2 *quat2;
  XAnimDeltaPartQuat *quat;
};

struct XAnimParts
{
  const char *name;
  unsigned __int16 dataByteCount;
  unsigned __int16 dataShortCount;
  unsigned __int16 dataIntCount;
  unsigned __int16 randomDataByteCount;
  unsigned __int16 randomDataIntCount;
  unsigned __int16 numframes;
  bool bLoop;
  bool bDelta;
  bool bDelta3D;
  bool bLeftHandGripIK;
  unsigned int streamedFileSize;
  unsigned __int8 boneCount[10];
  unsigned __int8 notifyCount;
  unsigned __int8 assetType;
  bool isDefault;
  unsigned int randomDataShortCount;
  unsigned int indexCount;
  float framerate;
  float frequency;
  float primedLength;
  float loopEntryTime;
  unsigned __int16 *names;
  unsigned __int8 *dataByte;
  __int16 *dataShort;
  int *dataInt;
  __int16 *randomDataShort;
  unsigned __int8 *randomDataByte;
  int *randomDataInt;
  XAnimIndices indices;
  XAnimNotifyInfo *notify;
  XAnimDeltaPart *deltaPart;
};

struct XAnim_s
{
  const char *debugName;
  unsigned int size;
  unsigned int paramSize;
  XAnimParam *params;
  const char **debugAnimNames;
  bool *wasLoggedIfMissing;
  XAnimEntry entries[1];
};

struct XAnimTree_s
{
  XAnim_s *anims;
  unsigned __int16 children;
  __int16 inst;
};

struct flameTable
{
  float flameVar_streamChunkGravityStart;
  float flameVar_streamChunkGravityEnd;
  float flameVar_streamChunkMaxSize;
  float flameVar_streamChunkStartSize;
  float flameVar_streamChunkEndSize;
  float flameVar_streamChunkStartSizeRand;
  float flameVar_streamChunkEndSizeRand;
  float flameVar_streamChunkDistScalar;
  float flameVar_streamChunkDistSwayScale;
  float flameVar_streamChunkDistSwayVelMax;
  float flameVar_streamChunkSpeed;
  float flameVar_streamChunkDecel;
  float flameVar_streamChunkVelocityAddScale;
  float flameVar_streamChunkDuration;
  float flameVar_streamChunkDurationScaleMaxVel;
  float flameVar_streamChunkDurationVelScalar;
  float flameVar_streamChunkSizeSpeedScale;
  float flameVar_streamChunkSizeAgeScale;
  float flameVar_streamChunkSpawnFireIntervalStart;
  float flameVar_streamChunkSpawnFireIntervalEnd;
  float flameVar_streamChunkSpawnFireMinLifeFrac;
  float flameVar_streamChunkSpawnFireMaxLifeFrac;
  float flameVar_streamChunkFireMinLifeFrac;
  float flameVar_streamChunkFireMinLifeFracStart;
  float flameVar_streamChunkFireMinLifeFracEnd;
  float flameVar_streamChunkDripsMinLifeFrac;
  float flameVar_streamChunkDripsMinLifeFracStart;
  float flameVar_streamChunkDripsMinLifeFracEnd;
  float flameVar_streamChunkRotationRange;
  float flameVar_streamSizeRandSinWave;
  float flameVar_streamSizeRandCosWave;
  float flameVar_streamDripsChunkInterval;
  float flameVar_streamDripsChunkMinFrac;
  float flameVar_streamDripsChunkRandFrac;
  float flameVar_streamSmokeChunkInterval;
  float flameVar_streamSmokeChunkMinFrac;
  float flameVar_streamSmokeChunkRandFrac;
  float flameVar_streamChunkCullDistSizeFrac;
  float flameVar_streamChunkCullMinLife;
  float flameVar_streamChunkCullMaxLife;
  float flameVar_streamFuelSizeStart;
  float flameVar_streamFuelSizeEnd;
  float flameVar_streamFuelLength;
  float flameVar_streamFuelNumSegments;
  float flameVar_streamFuelAnimLoopTime;
  float flameVar_streamFlameSizeStart;
  float flameVar_streamFlameSizeEnd;
  float flameVar_streamFlameLength;
  float flameVar_streamFlameNumSegments;
  float flameVar_streamFlameAnimLoopTime;
  float flameVar_streamPrimaryLightRadius;
  float flameVar_streamPrimaryLightRadiusFlutter;
  float flameVar_streamPrimaryLightR;
  float flameVar_streamPrimaryLightG;
  float flameVar_streamPrimaryLightB;
  float flameVar_streamPrimaryLightFlutterR;
  float flameVar_streamPrimaryLightFlutterG;
  float flameVar_streamPrimaryLightFlutterB;
  float flameVar_fireLife;
  float flameVar_fireLifeRand;
  float flameVar_fireSpeedScale;
  float flameVar_fireSpeedScaleRand;
  float flameVar_fireVelocityAddZ;
  float flameVar_fireVelocityAddZRand;
  float flameVar_fireVelocityAddSideways;
  float flameVar_fireGravity;
  float flameVar_fireGravityEnd;
  float flameVar_fireMaxRotVel;
  float flameVar_fireFriction;
  float flameVar_fireEndSizeAdd;
  float flameVar_fireStartSizeScale;
  float flameVar_fireEndSizeScale;
  float flameVar_fireBrightness;
  float flameVar_dripsLife;
  float flameVar_dripsLifeRand;
  float flameVar_dripsSpeedScale;
  float flameVar_dripsSpeedScaleRand;
  float flameVar_dripsVelocityAddZ;
  float flameVar_dripsVelocityAddZRand;
  float flameVar_dripsVelocityAddSideways;
  float flameVar_dripsGravity;
  float flameVar_dripsGravityEnd;
  float flameVar_dripsMaxRotVel;
  float flameVar_dripsFriction;
  float flameVar_dripsEndSizeAdd;
  float flameVar_dripsStartSizeScale;
  float flameVar_dripsEndSizeScale;
  float flameVar_dripsBrightness;
  float flameVar_smokeLife;
  float flameVar_smokeLifeRand;
  float flameVar_smokeSpeedScale;
  float flameVar_smokeVelocityAddZ;
  float flameVar_smokeGravity;
  float flameVar_smokeGravityEnd;
  float flameVar_smokeMaxRotation;
  float flameVar_smokeMaxRotVel;
  float flameVar_smokeFriction;
  float flameVar_smokeEndSizeAdd;
  float flameVar_smokeStartSizeAdd;
  float flameVar_smokeOriginSizeOfsZScale;
  float flameVar_smokeOriginOfsZ;
  float flameVar_smokeFadein;
  float flameVar_smokeFadeout;
  float flameVar_smokeMaxAlpha;
  float flameVar_smokeBrightness;
  float flameVar_smokeOriginOffset;
  float flameVar_collisionSpeedScale;
  float flameVar_collisionVolumeScale;
  const char *name;
  Material *fire;
  Material *smoke;
  Material *heat;
  Material *drips;
  Material *streamFuel;
  Material *streamFuel2;
  Material *streamFlame;
  Material *streamFlame2;
  const char *flameOffLoopSound;
  const char *flameIgniteSound;
  const char *flameOnLoopSound;
  const char *flameCooldownSound;
};

struct cStaticModel_s
{
  cStaticModelWritable writable;
  XModel *xmodel;
  int contents;
  vec3_t origin;
  vec3_t invScaledAxis[3];
  vec3_t absmin;
  vec3_t absmax;
};

struct WeaponCamo
{
  const char *name;
  GfxImage *solidBaseImage;
  GfxImage *patternBaseImage;
  WeaponCamoSet *camoSets;
  unsigned int numCamoSets;
  WeaponCamoMaterialSet *camoMaterials;
  unsigned int numCamoMaterials;
};

struct WeaponDef
{
  const char *szOverlayName;
  XModel **gunXModel;
  XModel *handXModel;
  const char *szModeName;
  unsigned __int16 *notetrackSoundMapKeys;
  unsigned __int16 *notetrackSoundMapValues;
  int playerAnimType;
  weapType_t weapType;
  weapClass_t weapClass;
  PenetrateType penetrateType;
  ImpactType impactType;
  weapInventoryType_t inventoryType;
  weapFireType_t fireType;
  weapClipType_t clipType;
  barrelType_t barrelType;
  int itemIndex;
  const char *parentWeaponName;
  int iJamFireTime;
  int overheatWeapon;
  float overheatRate;
  float cooldownRate;
  float overheatEndVal;
  bool coolWhileFiring;
  bool fuelTankWeapon;
  int iTankLifeTime;
  OffhandClass offhandClass;
  OffhandSlot offhandSlot;
  weapStance_t stance;
  const FxEffectDef *viewFlashEffect;
  const FxEffectDef *worldFlashEffect;
  const FxEffectDef *barrelCooldownEffect;
  int barrelCooldownMinCount;
  vec3_t vViewFlashOffset;
  vec3_t vWorldFlashOffset;
  const char *pickupSound;
  const char *pickupSoundPlayer;
  const char *ammoPickupSound;
  const char *ammoPickupSoundPlayer;
  const char *projectileSound;
  const char *pullbackSound;
  const char *pullbackSoundPlayer;
  const char *fireSound;
  const char *fireSoundPlayer;
  const char *fireLoopSound;
  const char *fireLoopSoundPlayer;
  const char *fireLoopEndSound;
  const char *fireLoopEndSoundPlayer;
  const char *fireStartSound;
  const char *fireStopSound;
  const char *fireKillcamSound;
  const char *fireStartSoundPlayer;
  const char *fireStopSoundPlayer;
  const char *fireKillcamSoundPlayer;
  const char *fireLastSound;
  const char *fireLastSoundPlayer;
  const char *emptyFireSound;
  const char *emptyFireSoundPlayer;
  const char *crackSound;
  const char *whizbySound;
  const char *meleeSwipeSound;
  const char *meleeSwipeSoundPlayer;
  const char *meleeHitSound;
  const char *meleeMissSound;
  const char *rechamberSound;
  const char *rechamberSoundPlayer;
  const char *reloadSound;
  const char *reloadSoundPlayer;
  const char *reloadEmptySound;
  const char *reloadEmptySoundPlayer;
  const char *reloadStartSound;
  const char *reloadStartSoundPlayer;
  const char *reloadEndSound;
  const char *reloadEndSoundPlayer;
  const char *rotateLoopSound;
  const char *rotateLoopSoundPlayer;
  const char *rotateStopSound;
  const char *rotateStopSoundPlayer;
  const char *deploySound;
  const char *deploySoundPlayer;
  const char *finishDeploySound;
  const char *finishDeploySoundPlayer;
  const char *breakdownSound;
  const char *breakdownSoundPlayer;
  const char *finishBreakdownSound;
  const char *finishBreakdownSoundPlayer;
  const char *detonateSound;
  const char *detonateSoundPlayer;
  const char *nightVisionWearSound;
  const char *nightVisionWearSoundPlayer;
  const char *nightVisionRemoveSound;
  const char *nightVisionRemoveSoundPlayer;
  const char *altSwitchSound;
  const char *altSwitchSoundPlayer;
  const char *raiseSound;
  const char *raiseSoundPlayer;
  const char *firstRaiseSound;
  const char *firstRaiseSoundPlayer;
  const char *adsRaiseSoundPlayer;
  const char *adsLowerSoundPlayer;
  const char *putawaySound;
  const char *putawaySoundPlayer;
  const char *overheatSound;
  const char *overheatSoundPlayer;
  const char *adsZoomSound;
  const char *shellCasing;
  const char *shellCasingPlayer;
  const char **bounceSound;
  const char *standMountedWeapdef;
  const char *crouchMountedWeapdef;
  const char *proneMountedWeapdef;
  int standMountedIndex;
  int crouchMountedIndex;
  int proneMountedIndex;
  const FxEffectDef *viewShellEjectEffect;
  const FxEffectDef *worldShellEjectEffect;
  const FxEffectDef *viewLastShotEjectEffect;
  const FxEffectDef *worldLastShotEjectEffect;
  vec3_t vViewShellEjectOffset;
  vec3_t vWorldShellEjectOffset;
  vec3_t vViewShellEjectRotation;
  vec3_t vWorldShellEjectRotation;
  Material *reticleCenter;
  Material *reticleSide;
  int iReticleCenterSize;
  int iReticleSideSize;
  int iReticleMinOfs;
  activeReticleType_t activeReticleType;
  vec3_t vStandMove;
  vec3_t vStandRot;
  vec3_t vDuckedOfs;
  vec3_t vDuckedMove;
  vec3_t vDuckedSprintOfs;
  vec3_t vDuckedSprintRot;
  vec2_t vDuckedSprintBob;
  float fDuckedSprintCycleScale;
  vec3_t vSprintOfs;
  vec3_t vSprintRot;
  vec2_t vSprintBob;
  float fSprintCycleScale;
  vec3_t vLowReadyOfs;
  vec3_t vLowReadyRot;
  vec3_t vRideOfs;
  vec3_t vRideRot;
  vec3_t vDtpOfs;
  vec3_t vDtpRot;
  vec2_t vDtpBob;
  float fDtpCycleScale;
  vec3_t vMantleOfs;
  vec3_t vMantleRot;
  vec3_t vSlideOfs;
  vec3_t vSlideRot;
  vec3_t vDuckedRot;
  vec3_t vProneOfs;
  vec3_t vProneMove;
  vec3_t vProneRot;
  vec3_t vStrafeMove;
  vec3_t vStrafeRot;
  float fPosMoveRate;
  float fPosProneMoveRate;
  float fStandMoveMinSpeed;
  float fDuckedMoveMinSpeed;
  float fProneMoveMinSpeed;
  float fPosRotRate;
  float fPosProneRotRate;
  float fStandRotMinSpeed;
  float fDuckedRotMinSpeed;
  float fProneRotMinSpeed;
  XModel **worldModel;
  XModel *worldClipModel;
  XModel *rocketModel;
  XModel *mountedModel;
  XModel *additionalMeleeModel;
  Material *fireTypeIcon;
  Material *hudIcon;
  weaponIconRatioType_t hudIconRatio;
  Material *indicatorIcon;
  weaponIconRatioType_t indicatorIconRatio;
  Material *ammoCounterIcon;
  weaponIconRatioType_t ammoCounterIconRatio;
  ammoCounterClipType_t ammoCounterClip;
  int iStartAmmo;
  int iMaxAmmo;
  int shotCount;
  const char *szSharedAmmoCapName;
  int iSharedAmmoCapIndex;
  int iSharedAmmoCap;
  bool unlimitedAmmo;
  bool ammoCountClipRelative;
  int damage[6];
  float damageRange[6];
  int minPlayerDamage;
  float damageDuration;
  float damageInterval;
  int playerDamage;
  int iMeleeDamage;
  int iDamageType;
  unsigned __int16 explosionTag;
  int iFireDelay;
  int iMeleeDelay;
  int meleeChargeDelay;
  int iDetonateDelay;
  int iSpinUpTime;
  int iSpinDownTime;
  float spinRate;
  const char *spinLoopSound;
  const char *spinLoopSoundPlayer;
  const char *startSpinSound;
  const char *startSpinSoundPlayer;
  const char *stopSpinSound;
  const char *stopSpinSoundPlayer;
  bool applySpinPitch;
  int iFireTime;
  int iLastFireTime;
  int iRechamberTime;
  int iRechamberBoltTime;
  int iHoldFireTime;
  int iDetonateTime;
  int iMeleeTime;
  int iBurstDelayTime;
  int meleeChargeTime;
  int iReloadTimeRight;
  int iReloadTimeLeft;
  int reloadShowRocketTime;
  int iReloadEmptyTimeLeft;
  int iReloadAddTime;
  int iReloadEmptyAddTime;
  int iReloadQuickAddTime;
  int iReloadQuickEmptyAddTime;
  int iReloadStartTime;
  int iReloadStartAddTime;
  int iReloadEndTime;
  int iDropTime;
  int iRaiseTime;
  int iAltDropTime;
  int quickDropTime;
  int quickRaiseTime;
  int iFirstRaiseTime;
  int iEmptyRaiseTime;
  int iEmptyDropTime;
  int sprintInTime;
  int sprintLoopTime;
  int sprintOutTime;
  int lowReadyInTime;
  int lowReadyLoopTime;
  int lowReadyOutTime;
  int contFireInTime;
  int contFireLoopTime;
  int contFireOutTime;
  int dtpInTime;
  int dtpLoopTime;
  int dtpOutTime;
  int crawlInTime;
  int crawlForwardTime;
  int crawlBackTime;
  int crawlRightTime;
  int crawlLeftTime;
  int crawlOutFireTime;
  int crawlOutTime;
  int slideInTime;
  int deployTime;
  int breakdownTime;
  int iFlourishTime;
  int nightVisionWearTime;
  int nightVisionWearTimeFadeOutEnd;
  int nightVisionWearTimePowerUp;
  int nightVisionRemoveTime;
  int nightVisionRemoveTimePowerDown;
  int nightVisionRemoveTimeFadeInStart;
  int fuseTime;
  int aiFuseTime;
  int lockOnRadius;
  int lockOnSpeed;
  bool requireLockonToFire;
  bool noAdsWhenMagEmpty;
  bool avoidDropCleanup;
  unsigned int stackFire;
  float stackFireSpread;
  float stackFireAccuracyDecay;
  const char *stackSound;
  float autoAimRange;
  float aimAssistRange;
  bool mountableWeapon;
  float aimPadding;
  float enemyCrosshairRange;
  bool crosshairColorChange;
  float moveSpeedScale;
  float adsMoveSpeedScale;
  float sprintDurationScale;
  weapOverlayReticle_t overlayReticle;
  WeapOverlayInteface_t overlayInterface;
  float overlayWidth;
  float overlayHeight;
  float fAdsBobFactor;
  float fAdsViewBobMult;
  bool bHoldBreathToSteady;
  float fHipSpreadStandMin;
  float fHipSpreadDuckedMin;
  float fHipSpreadProneMin;
  float hipSpreadStandMax;
  float hipSpreadDuckedMax;
  float hipSpreadProneMax;
  float fHipSpreadDecayRate;
  float fHipSpreadFireAdd;
  float fHipSpreadTurnAdd;
  float fHipSpreadMoveAdd;
  float fHipSpreadDuckedDecay;
  float fHipSpreadProneDecay;
  float fHipReticleSidePos;
  float fAdsIdleAmount;
  float fHipIdleAmount;
  float adsIdleSpeed;
  float hipIdleSpeed;
  float fIdleCrouchFactor;
  float fIdleProneFactor;
  float fGunMaxPitch;
  float fGunMaxYaw;
  float swayMaxAngle;
  float swayLerpSpeed;
  float swayPitchScale;
  float swayYawScale;
  float swayHorizScale;
  float swayVertScale;
  float swayShellShockScale;
  float adsSwayMaxAngle;
  float adsSwayLerpSpeed;
  float adsSwayPitchScale;
  float adsSwayYawScale;
  bool sharedAmmo;
  bool bRifleBullet;
  bool armorPiercing;
  bool bAirburstWeapon;
  bool bBoltAction;
  bool bUseAltTagFlash;
  bool bUseAntiLagRewind;
  bool bIsCarriedKillstreakWeapon;
  bool aimDownSight;
  bool bRechamberWhileAds;
  bool bReloadWhileAds;
  float adsViewErrorMin;
  float adsViewErrorMax;
  bool bCookOffHold;
  bool bClipOnly;
  bool bCanUseInVehicle;
  bool bNoDropsOrRaises;
  bool adsFireOnly;
  bool cancelAutoHolsterWhenEmpty;
  bool suppressAmmoReserveDisplay;
  bool laserSight;
  bool laserSightDuringNightvision;
  bool bHideThirdPerson;
  bool bHasBayonet;
  bool bDualWield;
  bool bExplodeOnGround;
  bool bThrowBack;
  bool bRetrievable;
  bool bDieOnRespawn;
  bool bNoThirdPersonDropsOrRaises;
  bool bContinuousFire;
  bool bNoPing;
  bool bForceBounce;
  bool bUseDroppedModelAsStowed;
  bool bNoQuickDropWhenEmpty;
  bool bKeepCrosshairWhenADS;
  bool bUseOnlyAltWeaoponHideTagsInAltMode;
  bool bAltWeaponAdsOnly;
  bool bAltWeaponDisableSwitching;
  Material *killIcon;
  weaponIconRatioType_t killIconRatio;
  bool flipKillIcon;
  bool bNoPartialReload;
  bool bSegmentedReload;
  bool bNoADSAutoReload;
  int iReloadAmmoAdd;
  int iReloadStartAdd;
  const char *szSpawnedGrenadeWeaponName;
  const char *szDualWieldWeaponName;
  unsigned int dualWieldWeaponIndex;
  int iDropAmmoMin;
  int iDropAmmoMax;
  int iDropClipAmmoMin;
  int iDropClipAmmoMax;
  int iShotsBeforeRechamber;
  bool blocksProne;
  bool bShowIndicator;
  int isRollingGrenade;
  int useBallisticPrediction;
  int isValuable;
  int isTacticalInsertion;
  bool isReviveWeapon;
  bool bUseRigidBodyOnVehicle;
  int iExplosionRadius;
  int iExplosionRadiusMin;
  int iIndicatorRadius;
  int iExplosionInnerDamage;
  int iExplosionOuterDamage;
  float damageConeAngle;
  int iProjectileSpeed;
  int iProjectileSpeedUp;
  int iProjectileSpeedRelativeUp;
  int iProjectileSpeedForward;
  float fProjectileTakeParentVelocity;
  int iProjectileActivateDist;
  float projLifetime;
  float timeToAccelerate;
  float projectileCurvature;
  XModel *projectileModel;
  weapProjExposion_t projExplosion;
  const FxEffectDef *projExplosionEffect;
  bool projExplosionEffectForceNormalUp;
  const FxEffectDef *projExplosionEffect2;
  bool projExplosionEffect2ForceNormalUp;
  const FxEffectDef *projExplosionEffect3;
  bool projExplosionEffect3ForceNormalUp;
  const FxEffectDef *projExplosionEffect4;
  bool projExplosionEffect4ForceNormalUp;
  const FxEffectDef *projExplosionEffect5;
  bool projExplosionEffect5ForceNormalUp;
  const FxEffectDef *projDudEffect;
  const char *projExplosionSound;
  const char *projDudSound;
  const char *mortarShellSound;
  const char *tankShellSound;
  bool bProjImpactExplode;
  bool bProjSentientImpactExplode;
  bool bProjExplodeWhenStationary;
  bool bBulletImpactExplode;
  WeapStickinessType stickiness;
  WeapRotateType rotateType;
  bool plantable;
  bool hasDetonator;
  bool timedDetonation;
  bool bNoCrumpleMissile;
  bool rotate;
  bool bKeepRolling;
  bool holdButtonToThrow;
  bool offhandHoldIsCancelable;
  bool freezeMovementWhenFiring;
  float lowAmmoWarningThreshold;
  bool bDisallowAtMatchStart;
  float meleeChargeRange;
  bool bUseAsMelee;
  bool isCameraSensor;
  bool isAcousticSensor;
  bool isLaserSensor;
  bool isHoldUseGrenade;
  float *parallelBounce;
  float *perpendicularBounce;
  const FxEffectDef *projTrailEffect;
  vec3_t vProjectileColor;
  guidedMissileType_t guidedMissileType;
  float maxSteeringAccel;
  int projIgnitionDelay;
  const FxEffectDef *projIgnitionEffect;
  const char *projIgnitionSound;
  float fAdsAimPitch;
  float fAdsCrosshairInFrac;
  float fAdsCrosshairOutFrac;
  int adsGunKickReducedKickBullets;
  float adsGunKickReducedKickPercent;
  float fAdsGunKickPitchMin;
  float fAdsGunKickPitchMax;
  float fAdsGunKickYawMin;
  float fAdsGunKickYawMax;
  float fAdsGunKickAccel;
  float fAdsGunKickSpeedMax;
  float fAdsGunKickSpeedDecay;
  float fAdsGunKickStaticDecay;
  float fAdsViewKickPitchMin;
  float fAdsViewKickPitchMax;
  float fAdsViewKickMinMagnitude;
  float fAdsViewKickYawMin;
  float fAdsViewKickYawMax;
  float fAdsRecoilReductionRate;
  float fAdsRecoilReductionLimit;
  float fAdsRecoilReturnRate;
  float fAdsViewScatterMin;
  float fAdsViewScatterMax;
  float fAdsSpread;
  int hipGunKickReducedKickBullets;
  float hipGunKickReducedKickPercent;
  float fHipGunKickPitchMin;
  float fHipGunKickPitchMax;
  float fHipGunKickYawMin;
  float fHipGunKickYawMax;
  float fHipGunKickAccel;
  float fHipGunKickSpeedMax;
  float fHipGunKickSpeedDecay;
  float fHipGunKickStaticDecay;
  float fHipViewKickPitchMin;
  float fHipViewKickPitchMax;
  float fHipViewKickMinMagnitude;
  float fHipViewKickYawMin;
  float fHipViewKickYawMax;
  float fHipViewScatterMin;
  float fHipViewScatterMax;
  float fAdsViewKickCenterDuckedScale;
  float fAdsViewKickCenterProneScale;
  float fAntiQuickScopeTime;
  float fAntiQuickScopeScale;
  float fAntiQuickScopeSpreadMultiplier;
  float fAntiQuickScopeSpreadMax;
  float fAntiQuickScopeSwayFactor;
  float fightDist;
  float maxDist;
  const char *accuracyGraphName[2];
  vec2_t *accuracyGraphKnots[2];
  vec2_t *originalAccuracyGraphKnots[2];
  int accuracyGraphKnotCount[2];
  int originalAccuracyGraphKnotCount[2];
  int iPositionReloadTransTime;
  float leftArc;
  float rightArc;
  float topArc;
  float bottomArc;
  float accuracy;
  float aiSpread;
  float playerSpread;
  float minTurnSpeed[2];
  float maxTurnSpeed[2];
  float pitchConvergenceTime;
  float yawConvergenceTime;
  float suppressTime;
  float maxRange;
  float fAnimHorRotateInc;
  float fPlayerPositionDist;
  const char *szUseHintString;
  const char *dropHintString;
  int iUseHintStringIndex;
  int dropHintStringIndex;
  float horizViewJitter;
  float vertViewJitter;
  float cameraShakeScale;
  int cameraShakeDuration;
  int cameraShakeRadius;
  float explosionCameraShakeScale;
  int explosionCameraShakeDuration;
  int explosionCameraShakeRadius;
  const char *szScript;
  float destabilizationRateTime;
  float destabilizationCurvatureMax;
  int destabilizeDistance;
  float *locationDamageMultipliers;
  const char *fireRumble;
  const char *meleeImpactRumble;
  const char *reloadRumble;
  const char *explosionRumble;
  TracerDef *tracerType;
  TracerDef *enemyTracerType;
  float adsDofStart;
  float adsDofEnd;
  float hipDofStart;
  float hipDofEnd;
  float scanSpeed;
  float scanAccel;
  int scanPauseTime;
  const char *flameTableFirstPerson;
  const char *flameTableThirdPerson;
  flameTable *flameTableFirstPersonPtr;
  flameTable *flameTableThirdPersonPtr;
  const FxEffectDef *tagFx_preparationEffect;
  const FxEffectDef *tagFlash_preparationEffect;
  bool doGibbing;
  float maxGibDistance;
  float altScopeADSTransInTime;
  float altScopeADSTransOutTime;
  int iIntroFireTime;
  int iIntroFireLength;
  const FxEffectDef *meleeSwipeEffect;
  const FxEffectDef *meleeImpactEffect;
  const FxEffectDef *meleeImpactNoBloodEffect;
  const char *throwBackType;
  WeaponCamo *weaponCamo;
  float customFloat0;
  float customFloat1;
  float customFloat2;
  int customBool0;
  int customBool1;
  int customBool2;
};

struct WeaponAttachmentUnique
{
  const char *szInternalName;
  eAttachment attachmentType;
  int siblingLink;
  int childLink;
  int combinedAttachmentTypeMask;
  const char *szAltWeaponName;
  unsigned int altWeaponIndex;
  const char *szDualWieldWeaponName;
  unsigned int dualWieldWeaponIndex;
  unsigned __int16 *hideTags;
  XModel *viewModel;
  XModel *viewModelAdditional;
  XModel *viewModelADS;
  XModel *worldModel;
  XModel *worldModelAdditional;
  const char *viewModelTag;
  const char *worldModelTag;
  vec3_t viewModelOffsets;
  vec3_t worldModelOffsets;
  vec3_t viewModelRotations;
  vec3_t worldModelRotations;
  vec3_t viewModelAddOffsets;
  vec3_t worldModelAddOffsets;
  vec3_t viewModelAddRotations;
  vec3_t worldModelAddRotations;
  WeaponCamo *weaponCamo;
  bool disableBaseWeaponAttachment;
  bool disableBaseWeaponClip;
  bool overrideBaseWeaponAttachmentOffsets;
  vec3_t viewModelOffsetBaseAttachment;
  vec3_t worldModelOffsetBaseAttachment;
  Material *overlayMaterial;
  Material *overlayMaterialLowRes;
  weapOverlayReticle_t overlayReticle;
  int iFirstRaiseTime;
  int iAltRaiseTime;
  int iAltDropTime;
  int iReloadAmmoAdd;
  int iReloadStartAdd;
  bool bSegmentedReload;
  const char **szXAnims;
  int animationOverrides[3];
  float *locationDamageMultipliers;
  int soundOverrides;
  const char *fireSound;
  const char *fireSoundPlayer;
  const char *fireLoopSound;
  const char *fireLoopSoundPlayer;
  const char *fireLoopEndSound;
  const char *fireLoopEndSoundPlayer;
  const char *fireStartSound;
  const char *fireStopSound;
  const char *fireStartSoundPlayer;
  const char *fireStopSoundPlayer;
  const char *fireLastSound;
  const char *fireLastSoundPlayer;
  const char *fireKillcamSound;
  const char *fireKillcamSoundPlayer;
  int effectOverrides;
  const FxEffectDef *viewFlashEffect;
  const FxEffectDef *worldFlashEffect;
  TracerDef *tracerType;
  TracerDef *enemyTracerType;
  float adsDofStart;
  float adsDofEnd;
  int iAmmoIndex;
  int iClipIndex;
  bool bOverrideLeftHandIK;
  bool bOverrideLeftHandProneIK;
  vec3_t ikLeftHandOffset;
  vec3_t ikLeftHandRotation;
  vec3_t ikLeftHandProneOffset;
  vec3_t ikLeftHandProneRotation;
  float customFloat0;
  float customFloat1;
  float customFloat2;
  int customBool0;
  int customBool1;
  int customBool2;
};

struct WeaponVariantDef
{
  const char *szInternalName;
  int iVariantCount;
  WeaponDef *weapDef;
  const char *szDisplayName;
  const char *szAltWeaponName;
  const char *szAttachmentUnique;
  WeaponAttachment **attachments;
  WeaponAttachmentUnique **attachmentUniques;
  const char **szXAnims;
  unsigned __int16 *hideTags;
  XModel **attachViewModel;
  XModel **attachWorldModel;
  const char **attachViewModelTag;
  const char **attachWorldModelTag;
  float attachViewModelOffsets[24];
  float attachWorldModelOffsets[24];
  float attachViewModelRotations[24];
  float attachWorldModelRotations[24];
  vec3_t stowedModelOffsets;
  vec3_t stowedModelRotations;
  unsigned int altWeaponIndex;
  int iAttachments;
  bool bIgnoreAttachments;
  int iClipSize;
  int iReloadTime;
  int iReloadEmptyTime;
  int iReloadQuickTime;
  int iReloadQuickEmptyTime;
  int iAdsTransInTime;
  int iAdsTransOutTime;
  int iAltRaiseTime;
  const char *szAmmoDisplayName;
  const char *szAmmoName;
  int iAmmoIndex;
  const char *szClipName;
  int iClipIndex;
  float fAimAssistRangeAds;
  float fAdsSwayHorizScale;
  float fAdsSwayVertScale;
  float fAdsViewKickCenterSpeed;
  float fHipViewKickCenterSpeed;
  float fAdsZoomFov1;
  float fAdsZoomFov2;
  float fAdsZoomFov3;
  float fAdsZoomInFrac;
  float fAdsZoomOutFrac;
  float fOverlayAlphaScale;
  float fOOPosAnimLength[2];
  bool bSilenced;
  bool bDualMag;
  bool bInfraRed;
  bool bTVGuided;
  unsigned int perks[2];
  bool bAntiQuickScope;
  Material *overlayMaterial;
  Material *overlayMaterialLowRes;
  Material *dpadIcon;
  weaponIconRatioType_t dpadIconRatio;
  bool noAmmoOnDpadIcon;
  bool mmsWeapon;
  bool mmsInScope;
  float mmsFOV;
  float mmsAspect;
  float mmsMaxDist;
  vec3_t ikLeftHandIdlePos;
  vec3_t ikLeftHandOffset;
  vec3_t ikLeftHandRotation;
  bool bUsingLeftHandProneIK;
  vec3_t ikLeftHandProneOffset;
  vec3_t ikLeftHandProneRotation;
  vec3_t ikLeftHandUiViewerOffset;
  vec3_t ikLeftHandUiViewerRotation;
};

struct WeaponDobjInfo
{
  unsigned __int8 numModelMasks;
  WeaponDobjInfo::Slot addingSlot;
  __int16 lastAddedModel;
  WeaponDobjInfo::ModelMask modelMasks[8];
};

struct ddlStructDef_t
{
  const char *name;
  int size;
  int memberCount;
  ddlMemberDef_t *members;
  ddlHash_t *hashTable;
};

struct ddlDef_t
{
  int version;
  int size;
  ddlStructDef_t *structList;
  int structCount;
  ddlEnumDef_t *enumList;
  int enumCount;
  ddlDef_t *next;
};

struct ddlState_t
{
  int absoluteOffset;
  int arrayIndex;
  ddlMemberDef_t *member;
  const ddlDef_t *ddl;
  ddlReturnCodes_e returnCode;
};

struct DObjSkelMat
{
  vec4_t axis[3];
  vec4_t origin;
};

struct _iobuf
{
  char *_ptr;
  int _cnt;
  char *_base;
  int _flag;
  int _file;
  int _charbuf;
  int _bufsiz;
  char *_tmpfname;
};

struct CmdArgs
{
  int nesting;
  LocalClientNum_t localClientNum[8];
  ControllerIndex_t controllerIndex[8];
  itemDef_s *itemDef[8];
  int argshift[8];
  int argc[8];
  const char **argv[8];
  char textPool[8192];
  const char *argvPool[512];
  int usedTextPool[8];
  int totalUsedArgvPool;
  int totalUsedTextPool;
};

struct msg_t
{
  int overflowed;
  int readOnly;
  unsigned __int8 *data;
  unsigned __int8 *splitData;
  int maxsize;
  int cursize;
  int splitSize;
  int readcount;
  int bit;
  int lastEntityRef;
  int flush;
  netsrc_t targetLocalNetID;
};

struct netProfileInfo_t
{
  netProfileStream_t send;
  netProfileStream_t recieve;
};

struct FastCriticalSection
{
  volatile int readCount;
  volatile int writeCount;
};

struct netchan_t
{
  int outgoingSequence;
  netsrc_t sock;
  int dropped;
  int incomingSequence;
  netadr_t remoteAddress;
  int qport;
  int fragmentSequence;
  int fragmentLength;
  unsigned __int8 *fragmentBuffer;
  int fragmentBufferSize;
  int unsentFragments;
  int unsentOnLoan;
  int unsentFragmentStart;
  int unsentLength;
  unsigned __int8 *unsentBuffer;
  int unsentBufferSize;
  int reliable_fragments;
  unsigned __int8 fragment_send_count[128];
  unsigned int fragment_ack[4];
  int lowest_send_count;
  netProfileInfo_t prof;
};

struct NetField
{
  const char *name;
  int offset;
  int size;
  int bits;
  unsigned __int8 changeHints;
  const char *bitsStr;
  const char *changeHintsStr;
};

struct GfxMarkContext
{
  unsigned __int8 lmapIndex;
  unsigned __int8 primaryLightIndex;
  unsigned __int8 reflectionProbeIndex;
  unsigned __int8 modelTypeAndSurf;
  unsigned __int16 modelIndex;
};

struct StringTable
{
  const char *name;
  int columnCount;
  int rowCount;
  StringTableCell *values;
  __int16 *cellIndex;
};

struct generic_avl_map_node_t
{
  void *m_data;
  unsigned int m_avl_key;
  phys_inplace_avl_tree_node<generic_avl_map_node_t> m_avl_node_info;
};

struct CEntPlayerInfo
{
  clientControllers_t *control;
  unsigned __int8 tag[6];
  float waterHeight;
  int nextWaterHeightCheck;
  int nextRippleTime;
};

struct ShaderConstantSet
{
  vec4_t value[7];
  unsigned __int8 constantSource[7];
  unsigned __int8 used;
};

struct cpose_t
{
  unsigned __int16 lightingHandle;
  unsigned __int8 eType;
  unsigned __int8 eTypeUnion;
  unsigned __int8 localClientNum;
  unsigned __int8 isRagdoll;
  int ragdollHandle;
  int physObjId;
  int physUserBody;
  int killcamRagdollHandle;
  int physUserBodyProneFeet;
  unsigned __int8 destructiblePose;
  int startBurnTime;
  float wetness;
  int cullIn;
  vec3_t origin;
  vec3_t angles;
  vec3_t absmin;
  vec3_t absmax;
  GfxSkinCacheEntry skinCacheEntry;
  $60D21612B457BDC98BEB77BAF7B9C3AE ___u19;
  ShaderConstantSet constantSet;
};

struct cgVehicle_t
{
  int lastGunnerFire[4];
  int wheelSurfType[6];
  int fireTime;
  int flags;
  float materialTime;
  float materialTime2;
  vehicle_cache_t *vehicle_cache;
  cgVehicleWheelEffect wheelEffects[3];
  unsigned int notes[2];
  int driveBySoundIndex[2];
  float driveBySoundDelay[2];
  float driveBySoundTimeout[2];
  float prevTurretPitch;
  float prevTurretYaw;
  float prevGunnerPitch[4];
  float prevGunnerYaw[4];
  float prevAngularVelocity[5];
  Engine engine;
  float minigunRotationSpeed;
  vec3_t gunSoundOrigins[5];
  unsigned __int8 wasFiring;
  vec3_t antennaPos[2];
  vec3_t antennaVel[2];
  vec3_t antennaParentBoneWorldAxis[2][3];
  vec3_t antennaRelativePos[2];
  vec3_t poseAxis[4];
};

struct centity_t
{
  cpose_t pose;
  LerpEntityState prevState;
  entityState_s nextState;
  __int16 previousEventSequence;
  int miscTime;
  int lastMuzzleFlash;
  int numShotsFiredLast;
  unsigned __int16 attachModelNames[2];
  unsigned __int16 attachTagNames[2];
  XAnimTree_s *tree;
  Destructible *destructible;
  NitrousVehicle *nitrousVeh;
  cLinkInfo_s *linkInfo;
  cgVehicle_t *vehicle;
  ClientTagCache *clientTagCache;
  AimTargetCache *aimTargetInfo;
  cgScriptMover_s *cScriptMover;
  canimscripted_t *scripted;
  cgZBarrier_s *zbarrier;
  DroppedWeaponDobjInfo *droppedWeaponDobjInfo;
  int nextSlideFX;
  unsigned __int16 flagIndex;
  unsigned __int16 flagState;
  Material *compassMaterial;
  int lastTrailTime;
  unsigned int fxTrailHandle;
  unsigned int fxProjExplosion;
  unsigned int fxHeartbeat;
  unsigned int fxLaserSight;
  vec3_t oldLinkOrigin;
  vec3_t originError;
  vec3_t anglesError;
  unsigned __int8 tracerDrawRateCounter;
  centity_t *updateDelayedNext;
  unsigned __int16 classname;
  unsigned int stepSound;
  unsigned __int8 footstepSurfaceOverride;
  unsigned __int8 deployedRiotshieldHits[8];
  $6C25AA3E8799A5F9AB61F53D73DF3D3B ___u38;
};

struct GfxBloom
{
  vec4_t visBloomLevelsRGBYInB;
  vec4_t visBloomLevelsRGBYInG;
  vec4_t visBloomLevelsRGBYInW;
  vec4_t visBloomLevelsRGBYOutB;
  vec4_t visBloomLevelsRGBYOutW;
  vec4_t visBloomRGBHi;
  vec4_t visBloomRGBLo;
  vec4_t visBloomYHi;
  vec4_t visBloomYLo;
};

struct GfxLight
{
  unsigned __int8 type;
  unsigned __int8 canUseShadowMap;
  unsigned __int8 shadowmapVolume;
  __int16 cullDist;
  vec3_t color;
  vec3_t dir;
  vec3_t origin;
  float radius;
  float cosHalfFovOuter;
  float cosHalfFovInner;
  int exponent;
  unsigned int spotShadowIndex;
  float dAttenuation;
  float roundness;
  vec3_t angles;
  float spotShadowHiDistance;
  vec4_t diffuseColor;
  vec4_t shadowColor;
  vec4_t falloff;
  vec4_t aAbB;
  vec4_t cookieControl0;
  vec4_t cookieControl1;
  vec4_t cookieControl2;
  __declspec(align(16)) float44 viewMatrix;
  float44 projMatrix;
  GfxLightDef *def;
};

struct GfxViewport
{
  int x;
  int y;
  int width;
  int height;
};

struct ExtraCamLodInfo
{
  vec3_t pos[4];
  unsigned int posValidBits;
};

struct lerpFrame_t
{
  float yawAngle;
  int yawing;
  float pitchAngle;
  int pitching;
  int animationNumber;
  animation_s *animation;
  int animationTime;
  vec3_t oldFramePos;
  float oldFrameYaw;
  float animSpeedScale;
  int oldFrameSnapshotTime;
};

struct clientInfo_t
{
  int infoValid;
  int nextValid;
  ClientNum_t clientNum;
  char name[32];
  team_t team;
  team_t oldteam;
  ffa_team_t ffaTeam;
  int clanAbbrev_IsEliteValidated;
  unsigned __int64 leagueTeamID;
  int leagueDivisionID;
  unsigned __int64 leagueSubdivisionID;
  Material *hLeagueDivisionIcon;
  int leagueSubdivisionRank;
  int rank;
  $137F9095F7597C63EB19E8F61F5887B0 ___u14;
  int needsRevive;
  unsigned int perks[2];
  unsigned __int64 xuid;
  char clanAbbrev[8];
  score_s score;
  Material *hStatusIcon;
  Material *hRankIcon;
  int location;
  int health;
  char model[64];
  char attachModelNames[6][64];
  char attachTagNames[6][64];
  unsigned int modelChecksum;
  unsigned int attachModelChecksums[6];
  unsigned int attachTagChecksums[6];
  lerpFrame_t legs;
  lerpFrame_t torso;
  float lerpMoveDir;
  float lerpLean;
  vec3_t playerAngles;
  int leftHandGun;
  int dobjDirty;
  clientControllers_t control;
  int lastDamageTime;
  int lastStandStartTime;
  int turnedHumanTime;
  __int64 moveType;
  __int64 eventType;
  int beingRevived;
  unsigned int clientConditions[25];
  XAnimTree_s *pXAnimTree;
  Weapon DObjWeapon;
  unsigned __int8 weaponModel;
  Weapon DObjOffhandWeapon;
  Weapon DObjMeleeWeapon;
  unsigned __int8 meleeWeaponModel;
  int showReloadClipInHand;
  int hideWeaponClipModel;
  int dropWeaponClipTime;
  int stanceTransitionTime;
  int turnAnimEndTime;
  char turnAnimType;
  int attachedVehEntNum;
  int attachedVehSeat;
  bool hideWeapon;
  unsigned int weaponHideBits[5];
  bool usingKnife;
  bool usingGrenade;
  bool usingLaser;
  int nextHideWeaponTime;
  vec3_t vehAnimLastOrg;
  vec3_t vehAnimLastAngle;
  int vehAnimLastBone;
  int vehAnimLastTime;
  int vehAnimLerpStartTime;
  int vehAnimLerpEndTime;
  float weaponSpinLerp;
  float lastWeaponSpinLerp;
  float weaponSpin;
  bool wasFiring[5];
  int laseFXCentNum;
  unsigned int laseFXHandle;
  int clientUIVisibilityFlags;
  int teleportTime;
  bool teleportBit;
  int surfaceType;
  int movementType;
  int footstepEventCount;
  SonarAttachmentInfo sonarAttachmentInfo;
  float infraredFadeOut;
  WeaponDobjInfo weaponDobjInfo;
  int offhandWeaponVisible;
};

struct actorLerpFrame_t
{
  int bAnimating;
  int animationState;
};

struct actorInfo_t
{
  int infoValid;
  int nextValid;
  int actorNum;
  int entityNum;
  char name[32];
  char model[64];
  char attachModelNames[6][64];
  char attachTagNames[6][64];
  unsigned int modelChecksum;
  unsigned int attachModelChecksums[6];
  unsigned int attachTagChecksums[6];
  unsigned int attachIgnoreCollision;
  animInfo_t animInfo;
  int animScriptedAnim;
  int nextAnimScriptedAnim;
  SonarAttachmentInfo sonarAttachmentInfo;
  int dobjDirty;
  XAnimTree_s *pXAnimTree;
};

struct visionSetVars_t
{
  bool filmEnable;
  vec4_t visBloomLevelsRGBYInB;
  vec4_t visBloomLevelsRGBYInG;
  vec4_t visBloomLevelsRGBYInW;
  vec4_t visBloomLevelsRGBYOutB;
  vec4_t visBloomLevelsRGBYOutW;
  vec4_t visBloomRGBHi;
  vec4_t visBloomRGBLo;
  vec4_t visBloomYHi;
  vec4_t visBloomYLo;
  vec4_t visColorRangeS;
  vec4_t visColorRangeE;
  vec4_t visColorShadowMatrixR;
  vec4_t visColorShadowMatrixG;
  vec4_t visColorShadowMatrixB;
  vec4_t visColorMidtoneMatrixR;
  vec4_t visColorMidtoneMatrixG;
  vec4_t visColorMidtoneMatrixB;
  vec4_t visColorHilightMatrixR;
  vec4_t visColorHilightMatrixG;
  vec4_t visColorHilightMatrixB;
  vec4_t visColorFinalGamma;
  vec4_t visColorFinalSaturation;
  vec4_t visColorFinalBlend;
  float filmLut;
  bool reviveEnable;
  float reviveEdgeColorTemp;
  float reviveEdgeSaturation;
  vec3_t reviveEdgeScale;
  vec3_t reviveEdgeContrast;
  vec3_t reviveEdgeOffset;
  float reviveEdgeMaskAdjust;
  float reviveEdgeAmount;
  bool charPrimaryUseTweaks;
  float charPrimaryDiffuseScale;
  float charPrimarySpecularScale;
  float masterRingmod;
  float reverbRingmod;
  float hiFilter;
  float lowFilter;
  vec4_t sunFlareTint;
  float postEmissiveBrightening;
  char name[64];
};

struct transPlayerState_t
{
  int otherFlags;
  int damageEvent;
  __int16 predictableEventSequence;
  int predictableEvents[4];
  __int16 unpredictableEventSequence;
  int unpredictableEvents[4];
};

struct bullet_hit_info_t
{
  vec3_t hitp;
  vec3_t hitn;
  int sflags;
  float depth;
  int hitid;
  float range;
};

struct snd_ambient_script_data
{
  bool isAmbientRoom;
  bool isAmbientPackage;
  bool isDefaultRoom;
  __int16 entnums[16];
  char priorities[16];
  char name[64];
  unsigned int hash;
  int numContexts;
  snd_context contexts[16];
};

struct ZBarrierDef
{
  const char *name;
  unsigned int generalRepairSound1;
  unsigned int generalRepairSound2;
  unsigned int upgradedGeneralRepairSound1;
  unsigned int upgradedGeneralRepairSound2;
  unsigned int delayBetweenRepSounds;
  float delayBetweenRepSoundsDuration;
  unsigned int earthquakeOnRepair;
  float earthquakeMinScale;
  float earthquakeMaxScale;
  float earthquakeMinDuration;
  float earthquakeMaxDuration;
  float earthquakeRadius;
  int numBoardsInBarrier;
  unsigned int autoHideOpenPieces;
  unsigned int taunts;
  unsigned int reachThroughAttacks;
  unsigned __int16 zombieTauntAnimState;
  unsigned __int16 zombieReachThroughAnimState;
  int numAttackSlots;
  float attackSpotHorzOffset;
  ZBarrierBoard boards[6];
};

struct animScriptItem_t
{
  int numConditions;
  animScriptCondition_t conditions[4];
  int numCommands;
  animScriptCommand_t commands[8];
};

struct animScript_t
{
  int numItems;
  animScriptItem_t *items[128];
};

struct scr_animtree_t
{
  XAnim_s *anims;
};

struct animScriptData_t
{
  animation_s animations[1024];
  unsigned int numAnimations;
  animScript_t scriptAnims[1][27];
  animScript_t scriptCannedAnims[1][27];
  animScript_t scriptStateChange[1][1];
  animScript_t scriptEvents[37];
  animScriptItem_t scriptItems[2158];
  int numScriptItems;
  scr_animtree_t animTree;
  unsigned __int16 bodyAnim;
  unsigned __int16 mainAnim;
  unsigned __int16 torsoAnim;
  unsigned __int16 legsAnim;
  unsigned __int16 turningAnim;
  SndAliasList *(__cdecl *soundAlias)(const char *);
  void (__cdecl *playSoundAlias)(ClientNum_t, SndAliasList *);
};

struct scr_anim_s
{
  $27710AC74C70326BDC4E77488F0FB9BC ___u0;
};

struct clientField_s
{
  int scriptCallbackFunc;
  clientFieldCodeCallback_s codeCallbackFunc;
  unsigned __int16 nameHash;
  unsigned int fieldOffset;
  unsigned int fieldType;
  float floatMin;
  float floatMax;
  unsigned int accessMask;
  int bSplitscreenHostOnly;
  int bCallbacksFor0WhenNew;
  unsigned __int8 bitOffset;
  bool obsolete;
  unsigned int numBits;
  unsigned int version;
};

struct bgsClientFields_s
{
  int bRegistrationFinished;
  clientFieldSet_s clientFieldSets[12];
  unsigned int fieldHash;
  unsigned int highestVersionUsed;
  bgsClientFieldCallbacks_s *pPendingCallbacks;
};

struct DObjModel_s
{
  XModel *model;
  unsigned __int16 boneName;
  unsigned __int16 parentModel;
  bool ignoreCollision;
  vec3_t trans;
  vec3_t rot;
};

struct DObj
{
  $912815140B19172F6168495ADE6CFF29 ___u0;
  unsigned __int16 duplicateParts;
  unsigned __int16 entnum;
  unsigned __int8 duplicatePartsSize;
  unsigned __int8 numModels;
  unsigned __int8 numBones;
  unsigned int ignoreCollision;
  volatile int locked;
  DSkel skel;
  float radius;
  unsigned int hidePartBits[5];
  char localClientIndex;
  unsigned __int8 flags;
  unsigned __int8 numRootAdjustMats;
  unsigned __int8 *ikState;
  $50B028246FCF571FDD896B3932BE9068 ___u15;
};

struct bot_goal_t
{
  vec3_t position;
  pathnode_t *node;
  float radius;
  int time;
  unsigned __int16 notify;
  BotGoalPriority priority;
};

struct bot_steering_t
{
  vec2_t anglesDesired;
  vec2_t anglesAverage;
  vec2_t anglesBase;
  float yawDelta;
  float pitchDelta;
};

struct SpawnVar
{
  bool spawnVarsValid;
  int numSpawnVars;
  char *spawnVars[64][2];
  int numSpawnVarChars;
  char spawnVarChars[2048];
};

struct trigger_info_t
{
  unsigned __int16 entnum;
  unsigned __int16 otherEntnum;
  int useCount;
  int otherUseCount;
};

struct com_parse_mark_t
{
  int lines;
  const char *text;
  int ungetToken;
  int backup_lines;
  const char *backup_text;
};

struct actorAntilagFrame_t
{
  vec3_t position[32];
  vec3_t angles[32];
  unsigned __int8 useCount[32];
  unsigned __int8 inUse[32];
  int time;
};

struct vehicleAntilagFrame_t
{
  vec3_t position[16];
  vec3_t angles[16];
  unsigned __int8 useCount[16];
  unsigned __int8 inUse[16];
  int time;
};

struct DynEntityDef
{
  DynEntityType type;
  GfxPlacement pose;
  XModel *xModel;
  XModel *destroyedxModel;
  unsigned __int16 brushModel;
  unsigned __int16 physicsBrushModel;
  const FxEffectDef *destroyFx;
  unsigned int destroySound;
  XModelPieces *destroyPieces;
  PhysPreset *physPreset;
  __int16 physConstraints[4];
  int health;
  int flags;
  int contents;
  unsigned __int16 targetname;
  unsigned __int16 target;
};

struct ViewModelInfo
{
  DObj *viewModelDObj;
  WeaponDobjInfo weaponDobjInfo;
  int hasAnimTree;
  XAnimTree_s *tree;
  XAnim_s *anims;
  unsigned int partBits[5];
  ViewModelHand hand[2];
};

struct GlassDef
{
  const char *name;
  int maxHealth;
  float thickness;
  float minShardSize;
  float maxShardSize;
  float shardLifeProbablility;
  int maxShards;
  Material *pristineMaterial;
  Material *crackedMaterial;
  Material *shardMaterial;
  const char *crackSound;
  const char *shatterShound;
  const char *autoShatterShound;
  const FxEffectDef *crackEffect;
  const FxEffectDef *shatterEffect;
};

struct Glass
{
  unsigned int numCellIndices;
  unsigned __int16 cellIndices[6];
  GlassDef *glassDef;
  unsigned int index;
  unsigned int brushModel;
  vec3_t origin;
  vec3_t angles;
  vec3_t absmin;
  vec3_t absmax;
  bool isPlanar;
  unsigned __int8 numOutlineVerts;
  unsigned __int8 binormalSign;
  vec2_t *outline;
  vec3_t outlineAxis[3];
  vec3_t outlineOrigin;
  float uvScale;
  float thickness;
};

struct IgnoreEntParams
{
  int baseEntity;
  int parentEntity;
  bool ignoreSelf;
  bool ignoreParent;
  bool ignoreSiblings;
  bool ignoreChildren;
};

struct HWND__
{
  int unused;
};

struct PolySet
{
  vec3_t *verts;
  int vertCount;
  int vertLimit;
  GfxDebugPoly *polys;
  int polyCount;
  int polyLimit;
};

struct trDebugSphere_t
{
  vec3_t center;
  float radius;
  int sideCount;
  vec4_t color;
  int depthTest;
};

struct HINSTANCE__
{
  int unused;
};

struct GfxScaledPlacement
{
  GfxPlacement base;
  float scale;
};

struct ScreenPlacement
{
  vec2_t scaleVirtualToReal;
  vec2_t scaleVirtualToFull;
  vec2_t scaleRealToVirtual;
  vec2_t virtualViewableMin;
  vec2_t virtualViewableMax;
  vec2_t virtualTweakableMin;
  vec2_t virtualTweakableMax;
  vec2_t realViewportBase;
  vec2_t realViewportSize;
  vec2_t realViewportMid;
  vec2_t realViewableMin;
  vec2_t realViewableMax;
  vec2_t realTweakableMin;
  vec2_t realTweakableMax;
  vec2_t subScreen;
  float hudSplitscreenScale;
};

struct GfxSceneDef
{
  int time;
  float floatTime;
  vec3_t viewOffset;
};

struct GfxUI3DBackend
{
  GfxViewport viewport[6];
  vec4_t uvSetup[6];
  int renderCmdCount[6];
  int renderCmdThatDrawsSomethingCount[6];
  int totalRenderCmds;
  int totalRenderCmdsThatDrawsSomething;
  float blurRadius;
};

struct GfxVertexBufferState
{
  volatile int used;
  int total;
  ID3D11Buffer *buffer;
  unsigned __int8 *verts;
};

struct GfxMatrix
{
  vec4_t m[4];
};

struct GfxAabbTree
{
  vec3_t mins;
  vec3_t maxs;
  unsigned __int16 childCount;
  unsigned __int16 surfaceCount;
  unsigned __int16 startSurfIndex;
  unsigned __int16 smodelIndexCount;
  unsigned __int16 *smodelIndexes;
  int childrenOffset;
};

struct GfxDrawPrimArgs
{
  int vertexCount;
  int triCount;
  int baseIndex;
};

struct GfxMeshData
{
  GfxMeshData *thisPtr;
  unsigned int indexCount;
  unsigned int totalIndexCount;
  ID3D11Buffer *ib;
  unsigned __int16 *indices;
  GfxVertexBufferState vb;
  unsigned int vertSize;
};

struct trDebugString_t
{
  vec3_t xyz;
  vec4_t color;
  float scale;
  char text[96];
};

struct trDebugLine_t
{
  vec3_t start;
  vec3_t end;
  vec4_t color;
  int depthTest;
};

struct DebugGlobals
{
  PolySet polySet;
  trDebugString_t *strings;
  int stringCount;
  int stringLimit;
  trDebugString_t *externStrings;
  int externStringCount;
  int externMaxStringCount;
  trDebugLine_t *lines;
  int lineCount;
  int lineLimit;
  trDebugLine_t *externLines;
  int externLineCount;
  int externMaxLineCount;
  GfxDebugPlume *plumes;
  int plumeCount;
  int plumeLimit;
  trDebugSphere_t *spheres;
  int sphereCount;
  int sphereLimit;
  trDebugSphere_t *externSpheres;
  int externSphereCount;
  int externMaxSphereCount;
};

struct GfxCmdBuf
{
  ID3D11DeviceContext *device;
  ID3D11CommandList **commandList;
  unsigned __int16 viewIndex;
  unsigned __int16 deviceIndex;
};

struct GfxParticleCloud
{
  GfxScaledPlacement placement;
  vec3_t velDirWorld;
  GfxColor color;
  vec2_t radius;
  unsigned __int16 count;
  unsigned __int16 offset;
  unsigned __int8 gaussian;
  unsigned __int8 pad[3];
};

struct GfxQRCodeBackend
{
  vec4_t scale[12];
};

struct GfxDrawSurfListInfo
{
  const GfxDrawSurf *drawSurfs;
  unsigned int drawSurfCount;
  unsigned __int8 baseTechType;
  const GfxViewInfo *viewInfo;
  vec4_t viewOrigin;
  OcclusionReportsMode occlusionReportsMode;
  int cameraView;
  int disableAllShadowTech;
  int needResolve;
};

struct GfxSunShadowProjection
{
  float viewMatrix[4][4];
  vec4_t switchPartition;
  vec4_t shadowmapScale;
};

struct GfxSunShadow
{
  GfxMatrix lookupMatrix;
  GfxSunShadowProjection sunProj;
  int sunShadowCount;
  __declspec(align(16)) GfxSunShadowPartition partition[2];
};

struct GfxFrameStats
{
  GfxStageStats stages[16];
  GfxPrimStatsStage currentStage;
  GfxPrimStatsTarget currentTarget;
  GfxFrameStats::<unnamed_type_counters> counters;
};

struct GfxCmdBufSourceState
{
  GfxCodeMatrices matrices;
  GfxCmdBufInput input;
  GfxViewParms viewParms;
  GfxMatrix shadowLookupMatrix;
  unsigned __int16 constVersions[243];
  unsigned __int16 matrixVersions[8];
  __declspec(align(16)) vec4_t eyeOffset;
  unsigned int shadowableLightForShadowLookupMatrix;
  const GfxScaledPlacement *objectPlacement;
  const GfxViewParms *viewParms3D;
  unsigned int depthHackFlags;
  GfxScaledPlacement skinnedPlacement;
  int cameraView;
  GfxViewMode viewMode;
  GfxSceneDef sceneDef;
  GfxViewport sceneViewport;
  GfxViewport scissorViewport;
  float materialTime;
  float destructibleBurnAmount;
  unsigned __int8 viewportBehavior;
  int renderTargetWidth;
  int renderTargetHeight;
  bool viewportIsDirty;
  bool scissorEnabled;
  unsigned int shadowableLightIndex;
};

struct GfxLightingSH
{
  vec4_t V0;
  vec4_t V1;
  vec4_t V2;
};

struct mnode_t
{
  unsigned __int16 cellIndex;
  unsigned __int16 rightChildOffset;
};

struct GfxLightingSHQuantized
{
  unsigned __int16 V0[4];
  unsigned __int16 V1[4];
  unsigned __int16 V2[4];
};

struct VariantWind
{
  vec3_t wind_vector;
  vec3_t rustle_angular_frequency;
  vec3_t rustle_amplitude;
  float blade_acceleration;
  float blade_velocity;
  int reset_timer;
  int gust_start;
  int gust_dur;
};

struct FX_WindInfo
{
  vec3_t windVector;
  float lowWindAltitude;
  float hiWindAltitude;
  float lowWindStrengthPercent;
  float windVectorMagnitude;
};

struct viewState_t
{
  playerState_s *ps;
  int damageTime;
  int time;
  float v_dmg_pitch;
  float v_dmg_roll;
  float xyspeed;
  float frametime;
  float fLastIdleFactor;
  int *removeMeUnusedInt;
};

struct WeaponComponentList
{
  int numComponents;
  int numAttachments;
  WeaponComponent components[8];
};

struct WeaponFullDef
{
  WeaponVariantDef weapVariantDef;
  WeaponDef weapDef;
  WeaponAttachment *attachments[63];
  WeaponAttachmentUnique *attachmentUniques[95];
  XModel *gunXModel[16];
  const char *szXAnims[88];
  unsigned __int16 hideTags[32];
  unsigned __int16 notetrackSoundMapKeys[20];
  unsigned __int16 notetrackSoundMapValues[20];
  XModel *worldModel[16];
  XModel *attachViewModel[8];
  XModel *attachWorldModel[8];
  const char *attachViewModelTag[8];
  const char *attachWorldModelTag[8];
  float parallelBounce[32];
  float perpendicularBounce[32];
  float locationDamageMultipliers[21];
  char weaponCamo[64];
};

struct ddlRoot_t
{
  const char *name;
  ddlDef_t *ddlDef;
};

struct FxImpactTable
{
  const char *name;
  FxImpactEntry *table;
};

struct SndDuck
{
  char name[32];
  unsigned int id;
  float fadeIn;
  float fadeOut;
  float startDelay;
  float distance;
  float length;
  unsigned int fadeInCurve;
  unsigned int fadeOutCurve;
  float *attenuation;
  float *filter;
  int updateWhilePaused;
};

struct SndAssetBankEntry
{
  unsigned int id;
  unsigned int size;
  unsigned int offset;
  unsigned int frameCount;
  unsigned __int8 frameRateIndex;
  unsigned __int8 channelCount;
  unsigned __int8 looping;
  unsigned __int8 format;
};

struct SndPatch
{
  char *name;
  unsigned int elementCount;
  unsigned int *elements;
};

struct MapEnts
{
  const char *name;
  char *entityString;
  int numEntityChars;
  MapTriggers trigger;
};

struct DynEntityClient
{
  int physObjId;
  unsigned __int16 flags;
  unsigned __int16 lightingHandle;
  int health;
  unsigned __int16 burnTime;
  unsigned __int16 fadeTime;
  int physicsStartTime;
};

struct DynEntityColl
{
  unsigned __int16 sector;
  unsigned __int16 nextEntInSector;
  vec3_t linkMins;
  vec3_t linkMaxs;
  int contents;
};

struct clipMap_t
{
  const char *name;
  int isInUse;
  ClipInfo info;
  ClipInfo *pInfo;
  unsigned int numStaticModels;
  cStaticModel_s *staticModelList;
  unsigned int numNodes;
  cNode_t *nodes;
  unsigned int numLeafs;
  cLeaf_s *leafs;
  unsigned int vertCount;
  vec3_t *verts;
  int triCount;
  unsigned __int16 *triIndices;
  unsigned __int8 *triEdgeIsWalkable;
  int partitionCount;
  CollisionPartition *partitions;
  int aabbTreeCount;
  CollisionAabbTree *aabbTrees;
  unsigned int numSubModels;
  cmodel_t *cmodels;
  int numClusters;
  int clusterBytes;
  unsigned __int8 *visibility;
  int vised;
  MapEnts *mapEnts;
  cbrush_t *box_brush;
  cmodel_t box_model;
  unsigned __int16 originalDynEntCount;
  unsigned __int16 dynEntCount[4];
  DynEntityDef *dynEntDefList[2];
  DynEntityPose *dynEntPoseList[2];
  DynEntityClient *dynEntClientList[2];
  DynEntityServer *dynEntServerList[2];
  DynEntityColl *dynEntCollList[4];
  int num_constraints;
  PhysConstraint *constraints;
  int max_ropes;
  rope_t *ropes;
  unsigned int checksum;
};

struct ComPrimaryLight
{
  unsigned __int8 type;
  unsigned __int8 canUseShadowMap;
  unsigned __int8 exponent;
  char priority;
  __int16 cullDist;
  unsigned __int8 useCookie;
  unsigned __int8 shadowmapVolume;
  vec3_t color;
  vec3_t dir;
  vec3_t origin;
  float radius;
  float cosHalfFovOuter;
  float cosHalfFovInner;
  float cosHalfFovExpanded;
  float rotationLimit;
  float translationLimit;
  float mipDistance;
  float dAttenuation;
  float roundness;
  vec4_t diffuseColor;
  vec4_t falloff;
  vec4_t angle;
  vec4_t aAbB;
  vec4_t cookieControl0;
  vec4_t cookieControl1;
  vec4_t cookieControl2;
  const char *defName;
};

struct ComWorld
{
  const char *name;
  int isInUse;
  unsigned int primaryLightCount;
  ComPrimaryLight *primaryLights;
};

struct pathnode_tree_t
{
  int axis;
  float dist;
  pathnode_tree_info_t u;
};

struct GameWorldSp
{
  const char *name;
  PathData path;
};

struct GameWorldMp
{
  const char *name;
  PathData path;
};

struct SunLightParseParams
{
  char name[64];
  GfxWorldSun initWorldSun[1];
  float fogTransitionTime;
  GfxWorldFog initWorldFog[1];
};

struct GfxLightCorona
{
  vec3_t origin;
  float radius;
  vec3_t color;
  float intensity;
};

struct DpvsPlane
{
  vec4_t coeffs;
  unsigned __int8 side[3];
  unsigned __int8 pad;
};

struct GfxPortal
{
  GfxPortalWritable writable;
  DpvsPlane plane;
  GfxCell *cell;
  vec3_t *vertices;
  unsigned __int8 vertexCount;
  vec3_t hullAxis[2];
  vec3_t bounds[2];
};

struct GfxCell
{
  vec3_t mins;
  vec3_t maxs;
  int aabbTreeCount;
  GfxAabbTree *aabbTree;
  int portalCount;
  GfxPortal *portals;
  unsigned __int8 reflectionProbeCount;
  unsigned __int8 *reflectionProbes;
};

struct GfxWorldDraw
{
  unsigned int reflectionProbeCount;
  $1F49717B0E1CA50A9A44728D0A9B0535 ___u1;
  $408AEAB81AC40492C090A33FB37AA44E ___u2;
  int lightmapCount;
  $A009777434B68680FCD4D45855F5D92C ___u4;
  $C5284B7EC33C3913887286D18902DB22 ___u5;
  $C8FE74EA23B54FF4265C68702E8C1551 ___u6;
  unsigned int vertexCount;
  unsigned int vertexDataSize0;
  GfxWorldVertexData0 vd0;
  unsigned int vertexDataSize1;
  GfxWorldVertexData1 vd1;
  int indexCount;
  unsigned __int16 *indices;
  ID3D11Buffer *indexBuffer;
};

struct GfxLightGrid
{
  unsigned int sunPrimaryLightIndex;
  unsigned __int16 mins[3];
  unsigned __int16 maxs[3];
  float offset;
  unsigned int rowAxis;
  unsigned int colAxis;
  unsigned __int16 *rowDataStart;
  unsigned int rawRowDataSize;
  unsigned __int8 *rawRowData;
  unsigned int entryCount;
  GfxLightGridEntry *entries;
  unsigned int colorCount;
  GfxCompressedLightGridColors *colors;
  unsigned int coeffCount;
  GfxCompressedLightGridCoeffs *coeffs;
  unsigned int skyGridVolumeCount;
  GfxSkyGridVolume *skyGridVolumes;
};

struct GfxBrushModel
{
  GfxBrushModelWritable writable;
  vec3_t bounds[2];
  unsigned int surfaceCount;
  unsigned int startSurfIndex;
};

struct sunflare_t
{
  bool hasValidData;
  Material *spriteMaterial;
  Material *flareMaterial;
  float spriteSize;
  float flareMinSize;
  float flareMinDot;
  float flareMaxSize;
  float flareMaxDot;
  float flareMaxAlpha;
  int flareFadeInTime;
  int flareFadeOutTime;
  float blindMinDot;
  float blindMaxDot;
  float blindMaxDarken;
  int blindFadeInTime;
  int blindFadeOutTime;
  float glareMinDot;
  float glareMaxDot;
  float glareMaxLighten;
  int glareFadeInTime;
  int glareFadeOutTime;
  vec3_t sunFxPosition;
};

struct GfxStaticModelInst
{
  vec3_t mins;
  vec3_t maxs;
  vec3_t lightingOrigin;
};

struct srfTriangles_t
{
  vec3_t mins;
  int vertexDataOffset0;
  vec3_t maxs;
  int vertexDataOffset1;
  int firstVertex;
  float himipRadiusInvSq;
  unsigned __int16 vertexCount;
  unsigned __int16 triCount;
  int baseIndex;
};

struct GfxSurface
{
  srfTriangles_t tris;
  Material *material;
  unsigned __int8 lightmapIndex;
  unsigned __int8 reflectionProbeIndex;
  unsigned __int8 primaryLightIndex;
  unsigned __int8 flags;
  vec3_t bounds[2];
};

struct GfxStaticModelDrawInst
{
  float cullDist;
  GfxPackedPlacement placement;
  XModel *model;
  int flags;
  float invScaleSq;
  unsigned __int16 lightingHandle;
  unsigned __int16 colorsIndex;
  GfxLightingSHQuantized lightingSH;
  unsigned __int8 primaryLightIndex;
  unsigned __int8 visibility;
  unsigned __int8 reflectionProbeIndex;
  unsigned int smid;
  GfxStaticModelLmapVertexInfo lmapVertexInfo[4];
};

struct GfxWorld
{
  const char *name;
  const char *baseName;
  int planeCount;
  int nodeCount;
  int surfaceCount;
  GfxWorldStreamInfo streamInfo;
  const char *skyBoxModel;
  SunLightParseParams sunParse;
  GfxLight *sunLight;
  unsigned int sunPrimaryLightIndex;
  unsigned int primaryLightCount;
  unsigned int coronaCount;
  GfxLightCorona *coronas;
  unsigned int shadowMapVolumeCount;
  GfxShadowMapVolume *shadowMapVolumes;
  unsigned int shadowMapVolumePlaneCount;
  GfxVolumePlane *shadowMapVolumePlanes;
  unsigned int exposureVolumeCount;
  GfxExposureVolume *exposureVolumes;
  unsigned int exposureVolumePlaneCount;
  GfxVolumePlane *exposureVolumePlanes;
  unsigned int worldFogVolumeCount;
  GfxWorldFogVolume *worldFogVolumes;
  unsigned int worldFogVolumePlaneCount;
  GfxVolumePlane *worldFogVolumePlanes;
  unsigned int worldFogModifierVolumeCount;
  GfxWorldFogModifierVolume *worldFogModifierVolumes;
  unsigned int worldFogModifierVolumePlaneCount;
  GfxVolumePlane *worldFogModifierVolumePlanes;
  unsigned int lutVolumeCount;
  GfxLutVolume *lutVolumes;
  unsigned int lutVolumePlaneCount;
  GfxVolumePlane *lutVolumePlanes;
  GfxSkyDynamicIntensity skyDynIntensity;
  GfxWorldDpvsPlanes dpvsPlanes;
  int cellBitsCount;
  GfxCell *cells;
  GfxWorldDraw draw;
  GfxLightGrid lightGrid;
  int modelCount;
  GfxBrushModel *models;
  vec3_t mins;
  vec3_t maxs;
  unsigned int checksum;
  int materialMemoryCount;
  MaterialMemory *materialMemory;
  sunflare_t sun;
  vec4_t outdoorLookupMatrix[4];
  GfxImage *outdoorImage;
  unsigned int *cellCasterBits;
  GfxSceneDynModel *sceneDynModel;
  GfxSceneDynBrush *sceneDynBrush;
  unsigned int *primaryLightEntityShadowVis;
  unsigned int *primaryLightDynEntShadowVis[2];
  unsigned int numSiegeSkinInsts;
  SSkinInstance *siegeSkinInsts;
  GfxShadowGeometry *shadowGeom;
  GfxLightRegion *lightRegion;
  GfxWorldDpvsStatic dpvs;
  GfxWorldDpvsDynamic dpvsDyn;
  float waterDirection;
  GfxWaterBuffer waterBuffers[2];
  const Material *waterMaterial;
  const Material *coronaMaterial;
  const Material *ropeMaterial;
  const Material *lutMaterial;
  unsigned int numOccluders;
  Occluder *occluders;
  unsigned int numOutdoorBounds;
  GfxOutdoorBounds *outdoorBounds;
  unsigned int heroLightCount;
  unsigned int heroLightTreeCount;
  GfxHeroLight *heroLights;
  GfxHeroLightTree *heroLightTree;
  unsigned int lightingFlags;
  int lightingQuality;
};

struct FontIcon
{
  const char *name;
  int numEntries;
  int numAliasEntries;
  FontIconEntry *fontIconEntry;
  FontIconAlias *fontIconAlias;
};

struct MenuList
{
  const char *name;
  int menuCount;
  menuDef_t **menus;
};

struct LocalizeEntry
{
  const char *value;
  const char *name;
};

struct SndCurve
{
  char name[32];
  unsigned int id;
  vec2_t points[8];
};

struct SndPan
{
  char name[32];
  unsigned int id;
  float front;
  float back;
  float center;
  float lfe;
  float left;
  float right;
};

struct SndDriverGlobals
{
  const char *name;
  unsigned int groupCount;
  SndVolumeGroup *groups;
  unsigned int curveCount;
  SndCurve *curves;
  unsigned int panCount;
  SndPan *pans;
  unsigned int duckGroupCount;
  SndDuckGroup *duckGroups;
  unsigned int contextCount;
  SndContext *contexts;
  unsigned int masterCount;
  SndMaster *masters;
  unsigned int voiceDuckCount;
  SndSidechainDuck *voiceDucks;
  unsigned int futzCount;
  SndFutz *futzes;
};

struct RawFile
{
  const char *name;
  int len;
  const char *buffer;
};

struct LeaderboardDef
{
  const char *name;
  unsigned int id;
  int columnCount;
  int dwColumnCount;
  int xpColId;
  int prestigeColId;
  LbColumnDef *columns;
  LbUpdateType updateType;
  int trackTypes;
};

struct XGlobals
{
  const char *name;
  int xanimStreamBufferSize;
  int cinematicMaxWidth;
  int cinematicMaxHeight;
  int extracamResolution;
  vec4_t screenClearColor;
  int bigestGumpSize;
  int gumpsCount;
  gump_info_t gumps[32];
  int bigestOverlaySize;
  int overlayCount;
  overlay_info_t overlays[32];
};

struct Glasses
{
  const char *name;
  unsigned int numGlasses;
  Glass *glasses;
  unsigned __int8 *workMemory;
  unsigned int workMemorySize;
  unsigned int smallAllocatorBlocks;
  unsigned int maxGroups;
  unsigned int maxShards;
  unsigned int maxPhysics;
  unsigned int shardMemorySize;
  unsigned int maxFreeCmd;
  unsigned int numSlots;
  unsigned int numVerts;
  unsigned int numIndices;
};

struct EmblemSet
{
  int colorCount;
  int layerCount;
  EmblemLayer *layers;
  int categoryCount;
  EmblemCategory *categories;
  int iconTypeCount;
  EmblemIconType *iconTypes;
  int bgCategoryCount;
  EmblemBGCategory *bgCategories;
  int iconCount;
  EmblemIcon *icons;
  int backgroundCount;
  EmblemBackground *backgrounds;
  int backgroundLookupCount;
  __int16 *backgroundLookup;
};

struct ScriptParseTree
{
  const char *name;
  int len;
  unsigned __int8 *buffer;
};

struct KeyValuePairs
{
  const char *name;
  int numVariables;
  KeyValuePair *keyValuePairs;
};

struct MemoryBlock
{
  const char *name;
  bool mainMem;
  bool videoMem;
  bool streamMem;
  unsigned int size;
  unsigned int alignment;
  unsigned __int8 *data;
};

struct AddonMapEnts
{
  const char *name;
  char *entityString;
  int numEntityChars;
  MapTriggers trigger;
  ClipInfo *info;
  unsigned int numSubModels;
  cmodel_t *cmodels;
  GfxBrushModel *models;
};

struct SkinnedVertsDef
{
  const char *name;
  unsigned int maxSkinnedVerts;
};

struct Qdb
{
  const char *name;
  int len;
  unsigned __int8 *buffer;
};

struct Slug
{
  const char *name;
  int len;
  unsigned __int8 *buffer;
};

struct FootstepTableDef
{
  const char *name;
  unsigned int sndAliasTable[32][7];
};

struct FootstepFXTableDef
{
  const char *name;
  const FxEffectDef *footstepFX[32];
};

union XAssetHeader
{
  XModelPieces *xmodelPieces;
  PhysPreset *physPreset;
  PhysConstraints *physConstraints;
  DestructibleDef *destructibleDef;
  XAnimParts *parts;
  XModel *model;
  Material *material;
  MaterialPixelShader *pixelShader;
  MaterialVertexShader *vertexShader;
  MaterialTechniqueSet *techniqueSet;
  GfxImage *image;
  SndBank *sound;
  SndPatch *soundPatch;
  clipMap_t *clipMap;
  ComWorld *comWorld;
  GameWorldSp *gameWorldSp;
  GameWorldMp *gameWorldMp;
  MapEnts *mapEnts;
  GfxWorld *gfxWorld;
  GfxLightDef *lightDef;
  Font_s *font;
  FontIcon *fontIcon;
  MenuList *menuList;
  menuDef_t *menu;
  LocalizeEntry *localize;
  WeaponVariantDef *weapon;
  WeaponAttachment *attachment;
  WeaponAttachmentUnique *attachmentUnique;
  WeaponCamo *weaponCamo;
  SndDriverGlobals *sndDriverGlobals;
  const FxEffectDef *fx;
  FxImpactTable *impactFx;
  RawFile *rawfile;
  StringTable *stringTable;
  LeaderboardDef *leaderboardDef;
  XGlobals *xGlobals;
  ddlRoot_t *ddlRoot;
  Glasses *glasses;
  TextureList *textureList;
  EmblemSet *emblemSet;
  ScriptParseTree *scriptParseTree;
  KeyValuePairs *keyValuePairs;
  VehicleDef *vehicleDef;
  MemoryBlock *memoryBlock;
  AddonMapEnts *addonMapEnts;
  TracerDef *tracerDef;
  SkinnedVertsDef *skinnedVertsDef;
  Qdb *qdb;
  Slug *slug;
  FootstepTableDef *footstepTableDef;
  FootstepFXTableDef *footstepFXTableDef;
  ZBarrierDef *zbarrierDef;
  void *data;
};

struct WeaponVariantDefHash
{
  int hash;
  int weaponIndex;
};

struct BulletFireParams
{
  int weaponEntIndex;
  int ignoreEntIndex;
  float damageMultiplier;
  int methodOfDeath;
  vec3_t origStart;
  vec3_t start;
  vec3_t end;
  vec3_t dir;
};

struct VehicleState
{
  int entity;
  vec3_t origin;
  vec3_t angles;
  vec3_t velocity;
  vec3_t angVelocity;
  vec3_t previousOrigin;
  vec3_t previousAngles;
  vec3_t bodyVelocity;
  vec2_t tilt;
  vec2_t tiltVelocity;
  vec3_t mins;
  vec3_t maxs;
  float targetHeightDelta;
  float lastGroundHeight;
  int clipmask;
  vec3_t groundNormal;
};

struct itemInfo_t
{
  __int16 index;
  __int16 dwIndex;
  __int16 dwBaseIndex;
  __int16 row;
  char unlockLevel;
  char unlockPLevel;
  char cost;
  unsigned __int8 isNullItem : 1;
  unsigned __int8 isPassive : 1;
  unsigned __int8 isValid : 1;
  unsigned __int8 count : 2;
  char dwCost;
  char allocationCost;
  unsigned __int8 dlcIndex;
  unsigned __int8 sortKey;
  __int16 momentumCost;
  loadoutSlot_t loadoutSlot;
  itemGroup_t group;
  gunLevelRow_t *firstGunLevelRow;
  int nameHash;
  int refHash;
  int defaultClassBits;
  unsigned __int8 numAttachments[6];
  char attachments[30];
  unsigned __int16 gunLevelIndex[30];
};

struct segment
{
  char *startPos;
  char *endPos;
  int numItems;
};

struct challengeTableRow_t
{
  const char *challengeStatName;
  int statNameHash;
  unsigned int maxVal;
  unsigned __int16 index;
  unsigned __int16 row;
  unsigned __int16 rewardXP;
  unsigned __int8 unlockLevel;
  unsigned __int8 unlockItem;
  unsigned __int8 unlockPLevel : 4;
  unsigned __int8 tableNumber : 3;
  char type;
  const char *unlockImageName;
  int unlockImageHash;
  unsigned int xPGroupMask;
  unsigned __int16 prerequisite;
  char group;
  unsigned __int8 isLifeTime : 1;
  unsigned __int8 isMastery : 1;
  unsigned __int8 isMaxLevel : 1;
  unsigned __int8 isItemUnlocked : 1;
  unsigned __int8 isExpert : 1;
  unsigned __int8 resetOnPrestige : 1;
  unsigned __int8 setGlobalStat : 1;
  unsigned int excludeItemsMask[8];
};

struct viewLerpWaypoint_s
{
  int iFrac;
  float fViewPercent;
};

struct MantleResults
{
  vec3_t dir;
  vec3_t startPos;
  vec3_t ledgePos;
  vec3_t endPos;
  int flags;
  int entityNum;
  int duration;
};

struct animStringItem_t
{
  const char *string;
  int hash;
};

struct IPakLoadedPackfile
{
  char name[64];
  IPakSection data;
  IPakSection index;
  int fh;
  int refCount;
  int priority;
};

struct IPakIndexEntry
{
  unsigned __int64 key;
  unsigned int offset;
  unsigned int size;
};

struct IPakWorkData
{
  IPakLoadedPackfile *pak;
  int indexReadOffset;
  int activeBuffer;
  unsigned int currentEntry;
  unsigned __int16 imageParts[5312];
  IPakIndexEntry indexBuffer[2][4096];
  int indexBufferOffset[2];
  int indexBufferState[2];
};

struct NetFieldList
{
  const NetField *array;
  unsigned int count;
  unsigned int bbPrintRandMax;
  unsigned int bbPrintCount;
  unsigned int bbChecksum;
  BitField bitFields;
  const char *fieldArrayName;
};

struct demoTaggedPlayers
{
  int count;
  int playerIndex[30];
};

struct demoDefaultBookmark
{
  unsigned __int32 type : 7;
  unsigned __int32 entityNumber : 10;
  unsigned __int32 clientNum1 : 5;
  unsigned __int32 clientNum2 : 5;
  unsigned __int32 actorNum : 5;
  unsigned __int32 eType : 5;
  unsigned __int32 roundNumber : 8;
  unsigned __int32 overrideEntityCamera : 1;
  unsigned __int32 scoreEventPriority : 7;
  int time;
  int entBirthTime;
};

struct demoFooter
{
  int version;
  int startTime;
  int endTime;
  demoDefaultMetaInfo info;
  int numConnectedPlayers;
  demoConnectedPlayers connectedPlayers[50];
  int numDefaultBookmarks;
  demoDefaultBookmark defaultBookmarks[2500];
  int numHeliPatches;
  demoHeliPatches heliPatches[32];
};

struct demoSnapshotData
{
  int messageNum;
  int serverCommandNum;
  int deltaNum;
  int serverTime;
  int physicsTime;
  int snapFlags;
  __declspec(align(128)) MatchState matchState;
  playerState_s ps[18];
  entityState_s ent[1024];
  int entClientMask[1024][2];
  int prevNumEntities;
  clientState_s client[18];
  int prevNumClients;
  actorState_s actor[32];
  int prevNumActors;
};

struct demoMemBlock
{
  int compressedSize;
  int uncompressedSize;
  unsigned __int8 compressedMsgBuf[65536];
};

struct uiInfo_s
{
  UiContext uiDC;
  int playerRefresh;
  int playerIndex;
  int timeIndex;
  int previousTimes[4];
  uiMenuCommand_t currentMenuType;
  bool allowScriptMenuResponse;
  char toastPopupTitle[256];
  char toastPopupDesc[256];
  char toastPopupIconName[256];
  int toastPopupDuration;
  int toastPopupTimeCounter;
  bool toastPopupOpened;
  int contractIndex;
};

struct qtime_s
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
};

struct WorkerCmdConditional
{
  void *address;
  unsigned int value;
};

struct clientDebugStringInfo_t
{
  int max;
  int num;
  trDebugString_t *strings;
  int *durations;
};

struct clientDebugLineInfo_t
{
  int max;
  int num;
  trDebugLine_t *lines;
  int *durations;
};

struct clientDebugSphereInfo_t
{
  int max;
  int num;
  trDebugSphere_t *spheres;
  int *durations;
};

struct AnimState
{
  unsigned __int16 name;
  unsigned __int16 notify;
  unsigned __int8 flags;
  unsigned __int8 size;
  AnimSubState *subStates;
};

struct AnimStateDef
{
  scr_animtree_t tree;
  unsigned __int16 name;
  unsigned __int16 size;
  AnimState *states;
};

struct FxBeam
{
  unsigned __int8 type;
  bool depthHack;
  unsigned __int8 drawSurfOverride;
  vec3_t begin;
  vec3_t end;
  GfxColor colors[5];
  float radius;
  Material *material;
  int segmentCount;
  $9929DD005638F3C6CDB502194214908B ___u9;
};

struct ShardGroup
{
  unsigned int packedPos;
  const GlassDef *glassDef;
  GlassShard *head;
  vec3_t worldBBoxMin;
  vec3_t worldBBoxMax;
  vec3_t origin;
  bool inGenVertsJob;
  bool invalidBBox;
  bool visible;
  bool highLod;
  __int16 numShards;
  __int16 numIndices;
  __int16 numVerts;
  unsigned __int16 lightingHandle;
  GfxLightingInfo lightingInfo;
  FxCodeMeshData *codeMesh;
  GfxDrawSurf *drawSurf;
  unsigned __int16 vertsBaseIndex;
  GfxPackedVertex *baseVerts;
  unsigned __int16 *renderIndices;
};

struct Allocator
{
  void *buffer;
  Allocator::Memory *head;
  Allocator::Memory *tail;
  Allocator::Memory *freeHead;
  int maxUsed;
};

struct GlassUpdateCmd
{
  GlassRenderer *renderer;
  GlassPhysics::StaticLocals staticLocals;
  float deltaTime;
  GlassShard *shards[32];
  unsigned int numShards;
};

struct trStatistics_t
{
  trViewStatistics_t *views;
  Image_MemUsage c_imageUsage;
};

struct GfxLodParms
{
  vec3_t origin;
  GfxLodRamp ramp[2];
  GfxLodRamp rampExtracam[2];
  bool valid;
  ExtraCamLodInfo extracamLod;
};

struct r_double_index_t
{
  unsigned __int16 value[2];
};

struct DiskGfxVertex
{
  vec3_t xyz;
  vec3_t normal;
  unsigned __int8 color[4];
  vec2_t texCoord;
  vec2_t lmapCoord;
  vec3_t tangent;
  vec3_t binormal;
};

struct qosPayload_t
{
  int protocol;
  int isMP;
  int isMigrating;
  int numAvailableSlots;
  int maxLocalPlayersAllowed;
  int allowGuests;
  int isMatchEnding;
  int isLoading;
  int isDedicated;
  unsigned __int64 xuid;
};

struct fileRetryInfo
{
  int lastAttemptTime;
  int lastAttemptInterval;
  int retryCount;
};

struct z_stream_s
{
  unsigned __int8 *next_in;
  unsigned int avail_in;
  unsigned int total_in;
  unsigned __int8 *next_out;
  unsigned int avail_out;
  unsigned int total_out;
  char *msg;
  internal_state *state;
  unsigned __int8 *(__cdecl *zalloc)(unsigned __int8 *, unsigned int, unsigned int);
  void (__cdecl *zfree)(unsigned __int8 *, unsigned __int8 *);
  unsigned __int8 *opaque;
  int data_type;
  unsigned int adler;
};

struct ct_data_s
{
  ct_data_s::<unnamed_type_fc> fc;
  ct_data_s::<unnamed_type_dl> dl;
};

struct tree_desc_s
{
  ct_data_s *dyn_tree;
  int max_code;
  static_tree_desc_s *stat_desc;
};

struct XZoneInfo
{
  const char *name;
  int allocFlags;
  int freeFlags;
};

struct persistentStats
{
  unsigned __int8 statsBuffer[50176];
  bool isChecksumValid;
  bool statsWriteNeeded;
  bool statsValidatedWithDDL;
  bool statsFetched;
  bool disableUpload;
};

struct dwFileShareListTask
{
  unsigned __int64 *ownerIDs;
  unsigned int numOwners;
  unsigned __int16 offset;
  unsigned __int16 category;
  unsigned __int16 maxNumResults;
  bdFileMetaData *descriptors;
  int *numDescriptors;
  int *totalDescriptors;
  bool isUserFile;
  const char *fileName;
  void (__cdecl *successCallback)(const ControllerIndex_t);
  void (__cdecl *failureCallback)(const ControllerIndex_t);
};

struct dwFileShareRemoveTask
{
  unsigned int fileSlot;
  void (__cdecl *successCallback)(const ControllerIndex_t, int);
  void (__cdecl *failureCallback)(const ControllerIndex_t);
};

struct dwFileShareSummaryTask
{
  unsigned __int64 fileID;
  unsigned __int8 *summaryData;
  unsigned int summaryDataSize;
  const void *metaData;
  unsigned int metaDataSize;
  unsigned int numTags;
  bdTag *tags;
  fileShareLocation location;
  bool showSuccess;
  void (__cdecl *successCallback)(const ControllerIndex_t, unsigned __int64);
  void (__cdecl *failureCallback)(const ControllerIndex_t);
};

struct GSPolicyResponse_t
{
  unsigned __int8 m_bSecure;
};

struct _EXCEPTION_POINTERS
{
  _EXCEPTION_RECORD *ExceptionRecord;
  _CONTEXT *ContextRecord;
};

struct statsDelta_t
{
  int minDelta;
  int maxDelta;
};

struct SndPlayback
{
  int id;
  float attenuation;
  int lengthMs;
  int playedMs;
  unsigned int aliasId;
  SndEntHandle entHandle;
  SndPlayback *next;
};

struct SndSpeakerMap
{
  int inputChannelCount;
  int outputChannelCount;
  float volumes[16];
};

struct SndCommand
{
  SndCommand *next;
  SndCommandType type;
  SndCommandContext context;
};

struct orientation_t
{
  vec3_t origin;
  vec3_t axis[3];
};

struct SndNotify
{
  SndNotify *next;
  SndNotifyType type;
  SndNotifyContext context;
};

struct SndFader
{
  float value;
  float goal;
  float rate;
};

struct SndDuckActive
{
  int inUse;
  SndDuckCategoryType category;
  int startTime;
  int endTime;
  int pingTime;
  vec3_t position;
  unsigned int id;
  const SndDuck *duck;
  float amount;
  float effect;
  SndVoice *voice;
  float padding[3];
};

struct SndListener
{
  orientation_t orient;
  ClientNum_t clientNum;
  bool active;
  team_t team;
};

struct PlayerSkill
{
  float skill;
  float variance;
  float score;
  int contrib;
};

union ddlValue_t
{
  float fixedPointValue;
  int intValue;
  unsigned int uintValue;
  unsigned __int64 int64Value;
  float floatValue;
  const char *stringPtr;
};

struct dwTeamClanLeaveTask
{
  unsigned __int64 teamID;
};

struct jsmn_parser
{
  unsigned int pos;
  int toknext;
  int toksuper;
};

struct jsmntok_t
{
  jsmntype_t type;
  int start;
  int end;
  int size;
  jsmnVal_u *val;
  jsmnPrimitiveType_e primType;
};

struct SndRvParams
{
  float frameRate;
  float smoothing;
  float earlyTime;
  float lateTime;
  float earlyGain;
  float lateGain;
  float lateGainProx[4];
  float returnGain;
  float earlyLpf;
  float lateLpf;
  float inputLpf;
  float dampLpf;
  float wallReflect[4];
  float dryGain;
  float earlySize;
  float lateSize;
  float diffusion;
  float angle;
  unsigned int delayMatrix;
  float returnHighpass;
  unsigned __int8 padding[8];
};

struct snd_occlusion_multiple
{
  SndOcclusionTrace *traces;
  unsigned int traceCount;
  unsigned int traceSequence;
  unsigned int *lastTraceSequence;
  unsigned int *occlusionTraceCount;
  unsigned int *occlusionVoiceCount;
  unsigned int *occlusionUsec;
};

struct SndDspBiQuadCoef
{
  float s[5];
};

struct sd_voice_param
{
  sd_voice_param_state state;
  sd_voice_param *next;
  SndBus bus;
  SndDspSourceParams dspParams;
  float dryPan[12];
  float wetPan[12];
  float pitch;
  int paused;
  int startPaused;
  int doPitch;
  char align[56];
};

struct sd_voice
{
  sd_voice_state state;
  int done;
  int hasData;
  __int64 position;
  float pitchFraction;
  sd_source source;
  sd_decoder *decoder;
  sd_decoder_output decoderOutput;
  SndDspSourceState dspState[2];
  unsigned int channelCount;
  int shutdownDueToStarvation;
  unsigned int starvedThisFrame;
  float dryPanFilter[12];
  float wetPanFilter[12];
  sd_voice_param *previousParam;
  char align[4];
};

struct sd_mix_master_param
{
  SndRvParams radverb;
  sd_mix_param_state state;
  sd_mix_bus_param bus;
  SndDspDynamoParam dyn1;
  SndDspDynamoParam dyn2;
  SndDspMasterEqParam eq;
  SndDspVoiceFilterParam voiceFilter;
  SndDspFutzParam gfutz;
  SndDspFutzParam pfutz;
  unsigned __int8 padding[36];
};

struct SndStartAliasInfo
{
  const SndAlias *alias;
  SndEntHandle sndEnt;
  vec3_t org;
  vec3_t dir;
  float volModStart;
  int timeshift;
  float fadetime;
  int startDelay;
  SndOcclusionStartCache *ocache;
  SndPlayback *playback;
  int playbackId;
  int secondaryId;
  bool startPaused;
  bool setScriptValues;
  float scriptPitch;
  float scriptPitchRate;
  float scriptAttenuation;
  float scriptAttenuationRate;
};

struct SndOverlayInfo
{
  char pszSampleName[128];
  char name[64];
  char spatial[8];
  int channel;
  float fGlobalPriority;
  float fLosOcclusion;
  float fDry;
  float fWet;
  float fDistance;
  float fPitch;
  int iEntity;
  int group;
  int pan;
  __int64 played;
  int bus;
  int duckGroup;
};

struct sentient_fields_s
{
  const char *name;
  unsigned int constId;
  int ofs;
  int size[1];
  fieldtype_t type;
  void (__cdecl *setter)(sentient_t *, const sentient_fields_s *);
  void (__cdecl *getter)(sentient_t *, const sentient_fields_s *);
};

struct PathBlockPlanes
{
  vec2_t vNormal[5];
  float fDist[5];
  int iPlaneCount;
};

struct pathsort_t
{
  pathnode_t *node;
  float metric;
  float distMetric;
};

struct sightclip_t
{
  vec3_t mins;
  vec3_t maxs;
  vec3_t outerSize;
  vec3_t start;
  vec3_t end;
  int passEntityNum[2];
  int contentmask;
};

struct pathnode_parent_t
{
  vec3_t origin_loc;
  int entnum;
  pathnode_t *m_node;
  pathnode_parent_t *m_next;
};

struct badplace_arc_t
{
  vec3_t origin;
  float radius;
  float halfheight;
  float angle0;
  float angle1;
};

struct scr_entref_t
{
  unsigned __int16 entnum;
  unsigned __int16 classnum;
  LocalClientNum_t client;
};

struct RadiantCommand
{
  RadiantCommandType type;
  int guid;
  char strCommand[512];
};

struct PotentialTargetData
{
  gentity_t *entity;
  int threat;
  float distToEnt;
  vec2_t dirToEnt;
};

struct team_move_other_context_t
{
  sentient_t *other;
  vec3_t vOrgOther;
  vec2_t vVelOther;
  vec2_t vDelta;
  vec2_t vPerp;
  float fPosDeltaLengthSqrd;
  float fScale;
};

struct team_move_context_t
{
  actor_t *self;
  vec2_t vVelSelf;
  vec3_t vOrgSelf;
  vec2_t vVelDirSelf;
  float fVelSelfSqrd;
  float fDeltaCorrection;
  float fIntervalSqrd;
  float fWalkIntervalSqrd;
  float fMaxIntervalSqrd;
  int bFailedLookahead;
  float fDodgePosDeltaLengthSqrd;
  int dodgeEntities[72];
  int dodgeEntityCount;
  sentient_t *pDodgeOther;
  bool bPileUp;
  float fSlowDownPosDeltaLengthSqrd;
  sentient_t *pSlowDownOther;
  vec2_t vVelSlowDownOther;
};

struct sentient_sort_t
{
  sentient_t *sentient;
  float fMetric;
  float distSqrd;
};

struct actor_fields_s
{
  const char *name;
  unsigned int constId;
  int ofs;
  int size[1];
  fieldtype_t type;
  void (__cdecl *setter)(actor_t *, const actor_fields_s *);
  void (__cdecl *getter)(actor_t *, const actor_fields_s *);
};

union badplace_parms_t
{
  badplace_arc_t arc;
  badplace_brush_t brush;
};

struct badplace_t
{
  int endtime;
  int pingTime;
  unsigned __int16 name;
  unsigned __int8 type;
  unsigned __int8 teamflags;
  int depth;
  badplace_parms_t parms;
};

struct weaponParms
{
  vec3_t forward;
  vec3_t right;
  vec3_t up;
  vec3_t muzzleTrace;
  vec3_t gunForward;
  Weapon weapon;
  const WeaponVariantDef *weapVariantDef;
  const WeaponDef *weapDef;
};

struct checkStopParams_t
{
  bool hadPath;
  vec3_t lastPathLookaheadDir;
  vec3_t lastPathGoal;
  const pathnode_t *node;
  const pathnode_t *prevNode;
};

struct PhysicsInputs
{
  vec3_t vVelocity;
  unsigned __int16 groundEntNum;
  int bHasGroundPlane;
  float groundplaneSlope;
  int iFootstepTimer;
};

union sval_u
{
  unsigned __int8 type;
  unsigned int stringValue;
  unsigned int idValue;
  float floatValue;
  int intValue;
  sval_u *node;
  unsigned int sourcePosValue;
  const unsigned __int8 *codePosValue;
  const char *debugString;
  scr_block_s *block;
};

struct scr_block_s
{
  int abortLevel;
  int localVarsCreateCount;
  int localVarsPublicCount;
  int localVarsCount;
  unsigned __int8 localVarsInitBits[8];
  scr_localVar_t localVars[64];
};

struct yy_buffer_state
{
  _iobuf *yy_input_file;
  char *yy_ch_buf;
  char *yy_buf_pos;
  unsigned int yy_buf_size;
  int yy_n_chars;
  int yy_is_our_buffer;
  int yy_is_interactive;
  int yy_at_bol;
  int yy_fill_buffer;
  int yy_buffer_status;
};

struct debugFileInfo_t
{
  const char *filename;
  void *startAddr;
  void *endAddr;
  unsigned __int8 **lineStartAddr;
  int lineStartAddrCount;
  char *source;
  int sourceLen;
  GSC_OBJGDB *gdb;
};

struct objFileInfo_t
{
  GSC_OBJ *activeVersion;
  GSC_OBJ *baselineVersion;
  debugFileInfo_t debugInfo;
  gscProfileInfo_t *profileInfo;
  int profileInfoCount;
};

struct ScriptExpression_t
{
  sval_u parseData;
  int breakonExpr;
  debugger_sval_s *exprHead;
};

struct _watchNode_t
{
  const char *refText;
  const char *valueText;
  unsigned int objectId;
  unsigned __int8 objectType;
  unsigned __int8 oldObjectType;
  VariableValue value;
  ScriptExpression_t expr;
  bool is_expand;
  bool is_valid_value;
  bool is_thread_list;
  bool is_endon_list;
};

struct flameGeneric_s
{
  flamePhysics_t phys;
  flameSize_t size;
  flameAge_t age;
  flameList_t listGlobal;
  flameList_t listLocal;
  flameStream_s *stream;
  unsigned __int32 type : 3;
  unsigned __int32 delete_chunk : 1;
  unsigned __int32 id : 28;
};

struct flameStream_s
{
  flameGeneric_s gen;
  flameRenderList_s *renderList;
  flameTable *flameVars;
  flameChunk_s *chunkList;
  int lastSmokeChunkTime;
  int lastDripChunkTime;
  int entityNum;
  int damage;
  float damageDuration;
  float damageInterval;
  int isKillcamFlame;
  int firingThroughGeo;
};

struct flameChunk_s
{
  flameGeneric_s gen;
  int spawnFireInterval;
  int lastSpawnFire;
  int spawnDripsInterval;
  int spawnSmokeInterval;
};

struct flameDrips_t
{
  flameGeneric_s gen;
  flameRender_s *flameRend;
};

struct flameFire_t
{
  flameGeneric_s gen;
  flameRender_s *flameRend;
};

struct flameWeaponConfig_t
{
  bool bIsFiring;
  bool bFireWhileIdle;
  vec3_t origin;
  vec3_t angle;
  float strength;
  float thickness;
  float burnRate;
  vec3_t entityOrigin;
  flameTable *fTable;
  int damage;
  float damageDuration;
  float damageInterval;
};

struct IKSystem
{
  bool bInitialized;
  char *boneStrings[24];
  IKBoneNames ikBoneParents[24];
  IKJointBones joints[4];
  int systemFrameNumber;
  unsigned __int16 *ikImportBoneStringVars;
  unsigned __int16 *ikImportMiscBoneStringVars;
  $61DB84DF2E94E53D7788C0F08FDC33D5 ___u7;
  const dvar_t *dvars[33];
  bool inViewer;
  vec3_t leftHandOffset;
  vec3_t leftHandRotation;
  int leftHandEntnum;
  int leftHandSwitchTime;
  int numActorIKEnabled;
  int numActorIKEnabledFrameNumber;
  vec3_t leftHandIdlePos;
  vec3_t leftHandOffsetPos;
  vec3_t leftHandOffsetRot;
  vec3_t leftHandPronePos;
  vec3_t leftHandProneRot;
};

struct localEntity_s
{
  localEntity_s *prev;
  localEntity_s *next;
  leType_t leType;
  int endTime;
  trajectory_t pos;
  GfxEntity refEntity;
  TracerInfo tracer;
};

struct Bone
{
  int parentBone;
  unsigned __int8 animBones[2];
  int rigidBody;
  float length;
  vec3_t center;
};

struct BoneOrientation
{
  vec3_t origin;
  int boneFlags;
  vec4_t orientation;
};

struct RagdollBody
{
  int references;
  int ragdollDef;
  int dobj;
  DObj *obj;
  const cpose_t *pose;
  vec3_t poseOffset;
  LocalClientNum_t localClientNum;
  RagdollBodyState state;
  int stateMsec;
  int stateFrames;
  int velCaptureMsec;
  int stableTime;
  int numBones;
  Bone bones[14];
  int numLerpBones;
  LerpBone lerpBones[9];
  int numJoints;
  Joint joints[28];
  int curOrientationBuffer;
  BoneOrientation boneOrientations[2][23];
  BoneOrientation lerpBoneOffsets[9];
  int flags;
  int storedLaunchCount;
  hitLocation_t storedLaunchHitLoc[2];
  vec3_t storedLaunchForce[2];
  hitLocation_t storedAttachHitLoc;
  int storedAttachEnt;
  int storedPhysObjId;
  rigid_body_constraint_point *debug_hang_point;
  rigid_body_constraint_point *hang_point;
  int start_hang_time;
  broad_phase_group *m_bpg;
  broad_phase_collision_pair *m_list_bpcp;
  int rope_id;
  void *rbc_dist;
  bool gravity_override;
  int gravity;
  vec3_t mover_xform_axis[14][3];
  vec3_t mover_xform_origin[14];
  float waterHeight;
};

struct BoneDef
{
  char animBoneTextNames[2][20];
  unsigned int animBoneNames[2];
  float radius;
  bool mirror;
  float percent;
  float mass;
  float friction;
  float buoyancy;
  int parentBone;
  PhysicsGeomType geomType;
};

struct JointDef
{
  unsigned __int8 bone;
  JointType type;
  int numLimitAxes;
  vec3_t limitAxes[3];
  float minAngles[3];
  float maxAngles[3];
  float axisFriction[3];
};

struct XDollBone
{
  unsigned __int8 index;
  unsigned __int8 flags;
  unsigned int name_hash;
  int rigidBody;
  PhysPreset *physPreset;
};

struct XDollBoneOrientation
{
  vec3_t origin;
  int boneFlags;
  vec4_t orientation;
};

struct XDoll_ConstraintInfo
{
  int type;
  int timer;
  $D6AB613C4141B769A65C0E9DC806C029 ___u2;
};

struct XDollBody
{
  int references;
  int entity_index;
  LocalClientNum_t client_index;
  int piece_index;
  unsigned int attach_bone_hash;
  PhysConstraints *constraintsDef;
  int numBones;
  XDollBone bones[4];
  XDollBoneOrientation boneOrientations[4];
  XDoll_ConstraintInfo constraintInfos[4];
  int userBody;
  unsigned int userBodyBoneHash;
  int stableTime;
};

struct leafList_s
{
  int count;
  int maxcount;
  int overflowed;
  unsigned __int16 *list;
  vec3_t bounds[2];
  int lastLeaf;
};

struct GfxVertex
{
  vec4_t xyzw;
  GfxColor color;
  vec2_t texCoord;
  PackedUnitVec normal;
};

struct debug_patch_info_t
{
  debug_patch_t patches[5000];
  unsigned int indices[100000];
  unsigned int num_patches;
  unsigned int num_indices;
};

struct chull_t
{
  unsigned int key;
  int nverts;
  phys_vec3 *verts;
  int ninds;
  unsigned __int16 *inds;
  chull_t *next;
  int touched;
  chull_t *next_list;
};

struct GfxPointVertex
{
  vec3_t xyz;
  unsigned __int8 color[4];
};

struct auto_rigid_body
{
  user_rigid_body *rb;
  const centity_t *cent;
  int frame_count;
  auto_rigid_body *next;
  phys_inplace_avl_tree_node<auto_rigid_body> m_avl_node_info;
};

struct DObjTrace_s
{
  float fraction;
  int sflags;
  vec3_t normal;
  unsigned __int16 modelIndex;
  unsigned __int16 partName;
  unsigned __int16 partGroup;
  int localBoneIndex;
};

struct collision_material_t
{
  char name[64];
  int cflags;
  int sflags;
};

struct SimplePlaneIntersection
{
  vec3_t xyz;
  int planeIndex[3];
};

struct XModelConfig
{
  XModelConfigEntry entries[4];
  float mins[3];
  float maxs[3];
  int collLod;
  unsigned int flags;
  char physicsPresetFilename[1024];
  char physicsConstraintsFilename[1024];
  char collMapFilename[1024];
  float bakeLightmapSampleSize;
  float lightingOriginOffsetX;
  float lightingOriginOffsetY;
  float lightingOriginOffsetZ;
  float lightingOriginRange;
};

struct XModelPartsLoad
{
  unsigned __int8 numBones;
  unsigned __int8 numRootBones;
  unsigned __int16 *boneNames;
  unsigned __int8 *parentList;
  __int16 *quats;
  float *trans;
  unsigned __int8 *partClassification;
  DObjAnimMat *baseMat;
};

struct XSurfaceGetTriCandidatesLocals
{
  int mins[3];
  int maxs[3];
  const XSurfaceCollisionTree *tree;
  const unsigned __int16 *inIndices;
  const unsigned __int8 *inVertices0;
  const unsigned __int8 *inVertices1;
  bool (__cdecl *visitorFunc)(void *, const unsigned __int8 **, const unsigned __int8 **);
  void *visitorContext;
  unsigned __int16 vertexSize0;
  unsigned __int16 surfaceFlags;
  unsigned int nodeQueueBegin;
  unsigned int nodeQueueEnd;
  unsigned int leafQueueBegin;
  unsigned int leafQueueEnd;
  unsigned int triangleQueueBegin;
  unsigned int triangleQueueEnd;
  unsigned int vertexQueueBegin;
  unsigned int vertexQueueEnd;
  QueueElement nodeQueue[64];
  QueueElement leafQueue[4];
  QueueElement triangleQueue[4];
  unsigned __int16 vertexQueue[4][3];
};

struct ClientNotifyData
{
  unsigned int notetrackName;
  unsigned int notifyType;
  unsigned int notifyName;
  float timeFrac;
};

struct XAnimServerNotifyList
{
  XAnimServerNotify *pList;
  int iNumElements;
  int iCurrentElement;
};

struct XModelNameMap
{
  unsigned __int16 name;
  unsigned __int16 index;
};

struct physBatch
{
  jqModule *Module;
  void *Input;
  void *Output;
};

struct tagPOINT
{
  int x;
  int y;
};

struct _DM_CMDCONT
{
  HRESULT (__cdecl *HandlingFunction)(_DM_CMDCONT *, char *, unsigned int);
  unsigned int DataSize;
  void *Buffer;
  unsigned int BufferSize;
  void *CustomData;
  unsigned int BytesRemaining;
};

struct _TOKEN_PRIVILEGES
{
  unsigned int PrivilegeCount;
  _LUID_AND_ATTRIBUTES Privileges[1];
};

struct sysEvent_t
{
  int evTime;
  sysEventType_t evType;
  int evValue;
  int evValue2;
  int evPtrLength;
  void *evPtr;
};

struct _XINPUT_GAMEPAD
{
  unsigned __int16 wButtons;
  unsigned __int8 bLeftTrigger;
  unsigned __int8 bRightTrigger;
  __int16 sThumbLX;
  __int16 sThumbLY;
  __int16 sThumbRX;
  __int16 sThumbRY;
};

struct GamePad
{
  bool enabled;
  bool keyboardEnabled;
  __int16 digitals;
  __int16 lastDigitals;
  float analogs[2];
  float lastAnalogs[2];
  float sticks[4];
  float lastSticks[4];
  bool stickDown[4][2];
  bool stickDownLast[4][2];
  float lowRumble;
  float highRumble;
  GamePad::<unnamed_type_feedback> feedback;
  _XINPUT_CAPABILITIES caps;
  _XINPUT_CAPABILITIES keyboardCaps;
};

struct winDmCommand
{
  unsigned int isBinarySend;
  unsigned int commandStrLength;
  unsigned int maxResponseLength;
};

struct AudioState
{
  unsigned __int8 AUDC;
  unsigned __int8 AUDV;
  unsigned __int8 AUDF;
  unsigned __int8 output;
  int dividerCount;
  int dividerMax;
  unsigned int poly_4;
  unsigned int poly_5;
  unsigned int poly_9;
};

struct TIAState
{
  void *pixels;
  int pitch;
  int height;
  int linePosition;
  int lineCount;
  int state;
  bool pendingVSync;
  int posP0;
  int posP1;
  int posM0;
  int posM1;
  int posBL;
  int HMP0;
  int HMP1;
  int HMM0;
  int HMM1;
  int HMBL;
  unsigned __int8 GRP0;
  unsigned __int8 GRP0D;
  unsigned __int8 GRP1;
  unsigned __int8 GRP1D;
  unsigned __int8 ENABL;
  unsigned __int8 ENABLD;
  unsigned __int8 GRPCache[4][9];
  unsigned __int8 GRPCached[4];
  unsigned __int8 CTRLPF;
  unsigned __int8 PF0;
  unsigned __int8 PF1;
  unsigned __int8 PF2;
  unsigned __int8 playFieldCache[40];
  bool playFieldDirty;
  unsigned __int8 NUSIZ0;
  unsigned __int8 REFP0;
  unsigned __int8 NUSIZ1;
  unsigned __int8 REFP1;
  unsigned __int8 xCache[2][160];
  bool xCacheDirty[2];
  AudioState audio[2];
  int audioCycles;
  int audioResampleCount;
  int audioReadSample;
  int audioWriteSample;
  unsigned __int8 audioBuffer[4096];
  SndDspBiquadState outputFilter;
  float dcBlockX;
  float dcBlockY;
  unsigned __int8 reg[64];
};

struct Machine
{
  MOSState MOS;
  PIAState PIA;
  TIAState TIA;
  ROMInfo *ROM;
  DPCState DPC;
  int bank;
  int paddle[4];
  unsigned int paddleCycles[4];
  int debug;
  unsigned int MOSCycles;
  unsigned int PIACycles;
  unsigned int TIACycles;
  unsigned int DPCCycles;
};

struct NTPMessage
{
  unsigned int header;
  unsigned int root_delay;
  unsigned int root_dispersion;
  unsigned int reference_indentifier;
  unsigned __int64 reference_timestamp;
  unsigned __int64 originate_timestamp;
  unsigned __int64 receive_timestamp;
  unsigned __int64 transmit_timestamp;
};

struct reliableClient
{
  netadr_t addr;
  int lastSendTime;
  int firstSendTime;
  unsigned __int8 nextSequence;
  int bufferUsed;
  int bytesAckd;
  unsigned __int8 reliableBuf[1000];
  reliableMsg msgs[20];
};

struct PhysicalMemoryPrim
{
  const char *allocName;
  unsigned int allocListCount;
  unsigned int pos;
  PhysicalMemoryAllocation allocList[80];
  EMemTrack memTrack;
};

struct PhysicalMemory
{
  const char *name;
  unsigned __int8 *buf;
  PhysicalMemoryPrim prim[2];
  unsigned int size;
};

struct HunkUserNull
{
  HunkUser hunkUser;
  int size;
  int alignment;
};

struct EvalValue
{
  EvalValueType type;
  EvalValue::<unnamed_type_u> u;
};

union PackedLmapCoords
{
  unsigned int packed;
};

struct iwd_t
{
  char iwdFilename[256];
  char iwdBasename[256];
  char iwdGamename[256];
  unsigned __int8 *handle;
  int checksum;
  int pure_checksum;
  volatile int hasOpenFile;
  int numFiles;
  unsigned __int8 referenced;
  unsigned int hashSize;
  fileInIwd_s **hashTable;
  fileInIwd_s *buildBuffer;
};

struct searchpath_s
{
  searchpath_s *next;
  iwd_t *iwd;
  directory_t *dir;
  int bLocalized;
  int ignore;
  int ignorePureCheck;
  int language;
};

struct OperandList
{
  Operand operands[10];
  int operandCount;
};

struct OperandStack
{
  OperandList stack[60];
  int numOperandLists;
};

struct pc_token_s
{
  int type;
  int subtype;
  int intvalue;
  float floatvalue;
  char string[1024];
};

struct expressionEntry
{
  int type;
  entryInternalData data;
  expressionEntry *next;
};

struct ExpressionAllocState
{
  int size;
  void *buffer;
};

struct bb_msg_t
{
  unsigned __int8 *data;
  int maxsize;
  int cursize;
  bool overflow;
  unsigned __int8 *pppHashTable;
  unsigned __int8 pppBits;
  unsigned int pppHash;
  int pppBitOffset;
  int pppBitCount;
};

struct GfxUI3DStack
{
  int stack[2];
  int size;
};

struct nestingStack_t
{
  int top;
  nestingStackElem_t members[64];
};

struct votingHandler_t
{
  const char *key;
  bool (__cdecl *handler)();
};

struct codtvDWContent_t
{
  fileShareLocation source;
  fileshareCategory_e category;
  filesharePlayerFilter_e playerFilter;
  fileshareDataFilter_e dataFilter;
};

struct codtvFolder_t
{
  int index;
  int parentIndex;
  char ref[16];
  char name[64];
  char customAction[32];
  codtvType_e type;
  char imageName[32];
  codtvImageCategory_e imageCategory;
  codtvContent_u content[32];
  int contentCount;
  unsigned __int64 userData;
};

struct sightpointtrace_t
{
  vec3_t start;
  vec3_t end;
  int passEntityNum[2];
  int contentmask;
  int locational;
  unsigned __int8 *priorityMap;
};

struct statmonitor_s
{
  int endtime;
  Material *material;
};

struct Block
{
  int num;
  int size;
  int timeout;
};

struct SaveHeader
{
  int saveVersion;
  int gameCheckSum;
  int saveCheckSum;
  int saveId;
  bool demoPlayback;
  bool splitscreen;
  int scrCheckSum[3];
  char mapName[256];
  char buildNumber[128];
  char gametype[256];
  char buildVersionSuffix[16];
  unsigned int networkProtocol;
  char screenShotName[64];
  char description[256];
  char filename[64];
  SaveType saveType;
  qtime_s time;
  int bodySize;
  unsigned int pad[8];
};

struct nodetype
{
  nodetype *left;
  nodetype *right;
  nodetype *parent;
  int weight;
  int symbol;
};

struct huff_t
{
  int blocNode;
  int blocPtrs;
  nodetype *tree;
  nodetype *loc[257];
  nodetype **freelist;
  nodetype nodeList[768];
  nodetype *nodePtrs[768];
};

struct huffman_t
{
  huff_t compressDecompress;
};

struct streamInfo
{
  int id;
  int file;
  unsigned int start_offset;
  unsigned int buffer_size;
  unsigned int bytes_read;
  unsigned __int8 *destination;
  int estMsToFinish;
  int startDeadline;
  $F3C83F9534AD9024CB1CCD2BC46B4BD8 ___u8;
  void *callbackUser;
  stream_status status;
  bool callbackOnly;
  streamInfo *nextInQueue;
  streamInfo *prevInQueue;
};

struct PathItem
{
  char name[64];
  PathItem *parent;
  PathItem *next;
};

struct callbackInfo
{
  void (__cdecl *callback)(int, stream_status, unsigned int, void *);
  int id;
  stream_status reason;
  unsigned int bytes;
  void *user;
};

struct PacketQueueBlock
{
  PacketQueueBlock *next;
  int readOffset;
  int writeOffset;
  unsigned __int8 data[16384];
};

struct PacketQueue
{
  PacketQueueBlock *head;
  PacketQueueBlock *tail;
  int queuedPackets;
  int queuedBytes;
  bool packetLost;
  bool packetReordered;
  int bucketBits;
  int bucketUpdateMS;
  const char *name;
  PacketQueue *nextQueue;
  bool emulation;
  int queuedBytesLimit;
  int queuedPacketsLimit;
  int latencyMS;
  int latencyJitterMS;
  int packetLossPercent;
  int packetLossRepeatPercent;
  int packetReorderPercent;
  int packetReorderRepeatPercent;
  int packetDuplicationPercent;
  int bucketBitsPerMS;
  int bucketBitsLimit;
};

struct meminfo_t
{
  int total[2];
  int nonSwapTotal;
  int nonSwapMinSpecTotal;
  int typeTotal[58][2];
};

struct field_t
{
  int cursor;
  int scroll;
  int drawWidth;
  int widthInPixels;
  float charHeight;
  int fixedSize;
  char buffer[256];
};

struct MapProfileEntry
{
  const char *label;
  int accessCount;
  unsigned __int64 ticksStart;
  unsigned __int64 ticksTotal;
  unsigned __int64 ticksSelf;
  int indent;
  MapProfileEntry *parent;
  MapProfileElement elements[3];
};

struct MapProfileElement
{
  unsigned __int64 ticksStart;
  unsigned __int64 ticksTotal;
  unsigned __int64 ticksSelf;
};

struct MapProfileHotSpot
{
  const char *label;
  int accessCount;
  __int64 ticksSelf;
  __int64 ticksFile;
};

struct areaParms_t
{
  const vec3_t *mins;
  const vec3_t *maxs;
  int *list;
  int count;
  int maxcount;
  int contentmask;
};

struct winding_t
{
  int numpoints;
  vec3_t p[4];
};

struct dwTwitchRegisterTask
{
  char accountName[256];
  char authToken[1024];
};

struct League
{
  int id;
  const char *name;
  const char *description;
  const char *icon;
  const char *news;
  bool teamsAllowed;
  bool randomsAllowed;
  int teamSize;
  int placementGames;
  float placementWindow;
  int bonusPool;
  int bonusPerWin;
  int bonusTimeUTC;
  int bonusDays;
  bool bonusCumulative;
  float eloMean;
  float eloScale;
  float eloK;
  float eloN;
  int eloAwards[20];
  int numSeasons;
  LeagueSeason seasons[16];
};

struct LeagueDivision
{
  int id;
  const char *name;
  const char *description;
  float minSkill;
  float maxSkill;
  float avgSkill;
  int subdivisionSize;
  bool canPlace;
  bool tweakSkill;
  int numIcons;
  LeagueDivisionIcon icons[6];
};

struct LeagueTeam
{
  LeagueStats baseStats;
  unsigned __int64 teamID;
  LeagueDivision *division;
  int memberCount;
  int input;
  float workingSkill;
  float workingVariance;
  LeagueStats newStats;
};

struct audioSample_t
{
  unsigned __int8 *buffer;
  int lengthInBytes;
  int lengthInSamples;
  int bytesPerSample;
  int frequency;
  bool stereo;
  int channels;
  int sampleOffset;
};

struct useList_t
{
  gentity_t *ent;
  float score;
};

struct GamerProfileBuffer
{
  unsigned __int8 exeSettings[1000];
  unsigned __int8 commonSettings[1000];
  bool isInitialized;
  bool isLoggedIn;
  bool errorOnRead;
};

struct antilagActorStore_t
{
  vec3_t position[32];
  vec3_t angles[32];
  unsigned __int8 actorMoved[32];
};

struct antilagVehicleStore_t
{
  vec3_t position[16];
  vec3_t angles[16];
  unsigned __int8 vehicleMoved[16];
};

struct ipFilter_s
{
  unsigned int mask;
  unsigned int compare;
};

struct SpawnPoint
{
  vec3_t origin;
  float weight[9];
  float baseWeight[9];
  int entNum;
  int teamMask;
  float yaw;
  int id;
  int orderNum;
  int dangerous;
  int dangerTimestamp[9];
  int scoreCullTime[9];
  vec3_t losCheckPos;
};

struct SpawnInfluencer
{
  bool used;
  bool active;
  bool archived;
  int influencerInstanceId;
  int debugEntityNum;
  int expireTime;
  int disableTime;
  int teamMask;
  EntHandle entity;
  SpawnInfluencerPreset *preset;
  float boundingRadius;
  vec2_t bounds;
  float length;
  vec3_t origin;
  vec3_t forward;
  vec3_t up;
  vec4_t quat;
  vec4_t worldQuat;
  vec3_t midPoint;
  int lastUpdateTime;
  float lastScore;
};

struct game_hudelem_s
{
  hudelem_s elem;
  ClientNum_t clientNum;
  int team;
  int archived;
};

union statValue_t
{
  int integer;
  unsigned int unsignedInt;
  __int64 integer64;
  unsigned __int64 unsignedInt64;
  float value;
};

struct saveField_t
{
  int ofs;
  saveFieldtype_t type;
};

struct game_hudelem_field_t
{
  const char *name;
  unsigned int constId;
  int ofs;
  int size;
  fieldtype_t type;
  int mask;
  int shift;
  void (__cdecl *setter)(game_hudelem_s *, int);
  void (__cdecl *getter)(game_hudelem_s *, int);
};

struct bot_threat_t
{
  gentity_t *ent;
  float dot;
  float distSq;
};

struct client_fields_s
{
  const char *name;
  unsigned int constId;
  int ofs;
  int size[1];
  fieldtype_t type;
  unsigned int whichbits;
  void (__cdecl *setter)(gclient_t *, const client_fields_s *);
  void (__cdecl *getter)(gclient_t *, const client_fields_s *);
};

struct vehicle_fields_s
{
  const char *name;
  unsigned int constId;
  int ofs;
  int size[1];
  fieldtype_t type;
  unsigned int whichbits;
  void (__cdecl *setter)(gentity_t *, const vehicle_fields_s *);
  void (__cdecl *getter)(gentity_t *, const vehicle_fields_s *);
};

struct EntHandleList
{
  unsigned __int16 infoIndex;
};

struct Avoid
{
  vec3_t pos;
  float radius;
  float maxSpeed;
  float timeHorizon;
  vec2_t vel;
  vec2_t prefVel;
  int priority;
  int entnum;
  int flags;
};

struct OrcaPlane
{
  vec2_t p;
  vec2_t n;
};

struct FxCurve
{
  int dimensionCount;
  int keyCount;
  float keys[1];
};

struct FxCurveIterator
{
  const FxCurve *master;
  int currentKeyIndex;
};

struct FxCamera
{
  vec3_t origin;
  volatile int isValid;
  vec4_t frustum[6];
  vec3_t axis[3];
  unsigned int frustumPlaneCount;
  unsigned int pad[2];
};

struct FxSpatialFrame
{
  vec4_t quat;
  vec3_t origin;
};

struct FxEffect
{
  orientation_t boneOffset;
  FxSpatialFrame frameAtSpawn;
  FxSpatialFrame frameNow;
  FxSpatialFrame framePrev;
  FxSpatialFrame effectToGroundEntAtSpawn;
  $80E152BBE5589C9FD82B51E0E28F7B38 ___u5;
  unsigned __int16 firstElemHandle[3];
  unsigned __int16 firstSortedElemHandle;
  unsigned __int16 firstTrailHandle;
  unsigned __int16 randomSeed;
  unsigned int ownerEffect;
  FxBoltAndSortOrder boltAndSortOrder;
  volatile int frameCount;
  int msecBegin;
  int msecLastUpdate;
  float distanceTraveled;
  volatile int elemCount[3];
  unsigned int uniqueHandle;
  float occlusionVisibility;
  vec4_t lightGridColor;
  float primaryLightFraction;
  int lightingOriginOffset;
  unsigned __int16 occlusionQueryHandle;
  __int16 groundEntityNum;
  __int16 occlusionRefCount;
  unsigned __int8 flags;
  unsigned __int8 culled;
};

struct FxElem
{
  unsigned __int8 defIndex;
  unsigned __int8 sequence;
  unsigned __int8 atRestFraction;
  unsigned __int8 emitResidual;
  int msecBegin;
  vec3_t baseVel;
  $92C7D7C95FE6DDC6EAFEF41256382E6F ___u6;
  FxElem::<unnamed_type_u> u;
  unsigned int attachedEffectHandle;
  unsigned __int8 windInterp;
  unsigned __int8 elemSpawnVisBits;
  unsigned __int8 pad[2];
};

struct FxTrail
{
  unsigned __int16 nextTrailHandle;
  unsigned __int16 firstElemHandle;
  unsigned __int16 lastElemHandle;
  char defIndex;
  char sequence;
};

struct FxTrailElem
{
  vec3_t origin;
  float spawnDist;
  int msecBegin;
  unsigned __int16 nextTrailElemHandle;
  __int16 baseVelZ;
  char basis[2][3];
  unsigned __int8 sequence;
  unsigned __int8 unused;
};

struct FxUniqueHandleDb
{
  FxUniqueHandleDb::Node nodes[1024];
  int firstFreeNode;
  int numNodesInUse;
  int pad[2];
};

struct FxPointGroup
{
  FxMarkPoint points[2];
  int next;
};

struct FxMarksGridCell
{
  __int16 x;
  __int16 y;
  __int16 z;
};

struct FxTriGroup
{
  unsigned __int16 indices[2][3];
  GfxMarkContext context;
  unsigned __int8 triCount;
  unsigned __int8 unused[1];
  int next;
};

struct FxMarksSystem
{
  FxMarksHashEntry gridHashTableEntries[256];
  FxMarksHashEntry *gridHashTable[256];
  FxMark marks[256];
  FxTriGroupPool triGroups[1024];
  FxPointGroupPool pointGroups[1536];
  unsigned __int16 entFirstMarkHandles[1792];
  int frameCount;
  unsigned __int16 firstFreeMarkHandle;
  unsigned __int16 firstActiveWorldMarkHandle;
  unsigned __int16 firstViewmodelMarkHandle;
  unsigned int numViewmodelMarks;
  FxTriGroupPool *firstFreeTriGroup;
  FxPointGroupPool *firstFreePointGroup;
  bool noMarks;
  bool hasCarryIndex;
  unsigned __int16 carryIndex;
  unsigned int allocedMarkCount;
  unsigned int freedMarkCount;
  int frameTime;
  int gridHashTableNumUsedEntries;
  int timeSinceLastGridUpdate;
};

struct FxCameraUpdate
{
  vec3_t vieworg;
  vec3_t viewaxis[3];
  float tanHalfFovX;
  float tanHalfFovY;
  float zfar;
};

struct FxSpawnEffectCmd
{
  vec4_t spawnAxis;
  vec3_t spawnPos;
  unsigned int newEffectUniqueHandle;
  const FxEffectDef *effectDef;
  int msecBegin;
  unsigned int ownerEffect;
  int dobjHandle;
  int boneIndex;
  int markEntnum;
  __int16 groundEntityNum;
  unsigned __int8 runnerSortOrder;
  unsigned __int8 localClientNum;
};

struct FxSystemBuffers
{
  FxEffectContainer effects[1024];
  FxPool<FxElem,FxElemContainer> elems[2048];
  FxPool<FxTrail,FxTrail> trails[128];
  FxPool<FxTrailElem,FxTrailElem> trailElems[2048];
  FxVisState visState[2];
  FxUniqueHandleDb uniqueHandleDb;
  unsigned __int8 ppuActionTypes[128];
  FxPPUAction ppuActions[128];
  unsigned __int8 padBuffer[80];
};

struct FxSprite
{
  Material *material;
  vec3_t pos;
  unsigned __int8 rgbaColor[4];
  float radius;
  float minScreenRadius;
  int flags;
};

struct FxPostLight
{
  vec3_t begin;
  vec3_t end;
  float radius;
  GfxColor color;
  Material *material;
};

struct FxPostLightInfo
{
  FxPostLight postLights[96];
  int postLightCount;
};

struct EffectElementDraw
{
  FxEffect *effect;
  r_double_index_t *firstIndex;
  unsigned __int16 firstParticleCloudIndex;
  unsigned __int16 firstVertex;
  unsigned __int16 numParticleCloudAlloc;
  unsigned __int16 numCodeMeshAlloc;
};

struct FxElemPreVisualState
{
  float sampleLerp;
  float sampleLerpInv;
  const FxElemVisStateSample *refStateMain;
  const FxElemVisStateSample *refState;
  int randomSeed;
  float distanceFade;
  float occlusionFade;
};

struct FxColor4b
{
  unsigned __int8 color[4];
};

struct FxGenerateVertsCmd
{
  FxSystem *system;
  FxBeamInfo *beamInfo;
  FxPostLightInfo *postLightInfo;
  FxSpriteInfo *spriteInfo;
  LocalClientNum_t localClientNum;
  vec3_t vieworg;
  vec3_t viewaxis[3];
  unsigned __int8 genVertsCameraType;
  int drawTime;
  FxSmpDrawBuffer *smpDrawBuffer;
};

struct FxProfileEntry
{
  const FxEffectDef *effectDef;
  int effectCount;
  int activeElemCount;
  int pendingElemCount;
  int trailCount;
  int activeTrailElemCount;
  int pendingTrailElemCount;
};

struct GfxConfiguration
{
  unsigned int maxClientViews;
  unsigned int entCount;
  unsigned int entnumNone;
  unsigned int entnumOrdinaryEnd;
  int threadContextCount;
  int critSectCount;
};

struct GfxWorldVertex
{
  vec3_t xyz;
  float binormalSign;
  GfxColor color;
  vec2_t texCoord;
  PackedUnitVec normal;
  PackedUnitVec tangent;
  vec2_t lmapCoord;
};

struct FxMarkTri
{
  unsigned __int16 indices[3];
  GfxMarkContext context;
};

struct MarkInfo
{
  vec3_t origin;
  vec3_t localOrigin;
  vec3_t localTexCoordAxis;
  vec3_t axis[3];
  float radius;
  Material *material;
  int maxTris;
  FxMarkTri *tris;
  int maxPoints;
  FxMarkPoint *points;
  vec3_t mins;
  vec3_t maxs;
  MarkClipPlaneSet clipPlanes;
  vec3_t viewOffset;
  bool markHasLightmap;
  bool markHasReflection;
  MarkFragmentsAgainstEnum markAgainst;
  unsigned __int16 smodelsCollided[32];
  int smodelCollidedCount;
  MarkInfoCollidedDObj sceneDObjsCollided[32];
  int sceneDObjCollidedCount;
  MarkInfoCollidedBModel sceneBModelsCollided[32];
  int sceneBModelCollidedCount;
  MarkInfoCollidedDObj viewmodelDObjsCollided[1];
  int viewmodelDObjsCollidedCount;
  int usedTriCount;
  int usedPointCount;
  void (__cdecl *callback)(void *, int, FxMarkTri *, int, FxMarkPoint *, const vec3_t *, const vec3_t *);
  void *callbackContext;
};

struct FxEditorElemDef
{
  char name[256];
  int editorFlags;
  int flags;
  FxFloatRange spawnRange;
  FxFloatRange fadeInRange;
  FxFloatRange fadeOutRange;
  float spawnFrustumCullRadius;
  FxSpawnDefLooping spawnLooping;
  FxSpawnDefOneShot spawnOneShot;
  FxIntRange spawnDelayMsec;
  FxIntRange lifeSpanMsec;
  FxFloatRange spawnOrigin[3];
  FxFloatRange spawnOffsetRadius;
  FxFloatRange spawnOffsetHeight;
  FxFloatRange spawnAngles[3];
  FxFloatRange angularVelocity[3];
  FxFloatRange initialRotation;
  vec4_t rotationAxis;
  FxFloatRange gravity;
  FxFloatRange elasticity;
  FxEditorElemAtlas atlas;
  float timeScale;
  float windInfluence;
  vec3_t velScale[2];
  const FxCurve *velShape[2][3][2];
  float rotationScale;
  const FxCurve *rotationShape[2];
  float sizeScale[2];
  const FxCurve *sizeShape[2][2];
  float scaleScale;
  const FxCurve *scaleShape[2];
  const FxCurve *color[2];
  const FxCurve *alpha[2];
  float lightingFrac;
  vec3_t collOffset;
  float collRadius;
  const FxEffectDef *effectOnImpact;
  const FxEffectDef *effectOnDeath;
  int sortOrder;
  const FxEffectDef *emission;
  FxFloatRange emitDist;
  FxFloatRange emitDistVariance;
  const FxEffectDef *attachment;
  unsigned __int8 elemType;
  int visualCount;
  $CE382E0EDD6E14D9768219063ECA85E1 ___u45;
  int trailSplitDist;
  int trailRepeatDist;
  float trailScrollTime;
  FxEditorTrailDef trailDef;
  int alphaFadeTimeMsec;
  int maxWindMagnitude;
  int spawnIntervalAtMaxWind;
  int lifespanAtMaxWind;
  float billboardTopWidth;
  float billboardBottomWidth;
  FxElemSpawnSound spawnSound;
  FxIntRange cloudDensityRange;
  vec2_t billboardPivot;
  float spotLightFovInnerFraction;
  float spotLightStartRadius;
  float spotLightEndRadius;
};

struct FxEditorEffectDef
{
  char name[64];
  int elemCount;
  unsigned __int16 flags;
  unsigned __int8 editorFlags;
  unsigned __int8 edPriority;
  vec3_t boundMin;
  vec3_t boundMax;
  vec3_t boundCenter;
  vec3_t boundSize;
  float occlusionQueryDepthBias;
  int occlusionQueryFadeIn;
  int occlusionQueryFadeOut;
  FxFloatRange occlusionQueryScaleRange;
  FxEditorElemDef elems[32];
};

struct FxFlagOutputSet
{
  int *flags[4];
};

struct FxElemSetupCmd
{
  FxSystem *system;
  int effectStart;
  int effectLast;
  FxElemBits *elemDrawBits;
  FxElemRenderState *elemRenderStates;
  int drawTime;
  unsigned int cameraType;
  EffectElemCountInfo *effectElemCountInfo;
  volatile int *effectElemCountInfoIndex;
};

struct FxDrawSpriteGeoCmd
{
  EffectElementDraw *effectElemDrawFirst;
  EffectElementDraw *effectElemDrawLast;
  FxElemBits *elemDrawBits;
  FxSystem *system;
  int drawTime;
  FxElemRenderState *elemRenderStates;
  int cameraType;
};

struct FxDrawTrailGeoCmd
{
  int trailEffectFirst;
  int trailEffectLast;
  const unsigned __int16 *effectHandles;
  const FxDrawTrailResourceRequired *resourceRequiredArray;
  const FxDrawTrailResource *resourceArray;
  FxSystem *system;
  int drawTime;
  unsigned int cameraType;
};

struct DynEntityConstraintCreateParams
{
  char classname[64];
  char targetname[64];
  char target[64];
  char target2[64];
  vec3_t origin;
  vec3_t origin2;
  vec3_t angles;
  int health;
  float minAngle;
  float maxAngle;
  float damp;
  float distance;
  float scale;
  float force_scale;
  float width;
  int spawnflags;
  float timeout;
  char materialname[64];
};

struct DevMenuItem
{
  char label[26];
  unsigned __int8 childType;
  unsigned __int8 childMenuMemory;
  __int16 sortKey;
  unsigned __int16 nextSibling;
  unsigned __int16 prevSibling;
  unsigned __int16 parent;
  DevMenuChild child;
};

struct XAsset
{
  XAssetType type;
  XAssetHeader header;
};

struct XBlock
{
  unsigned __int8 *data;
  unsigned int size;
};

struct XAssetEntry
{
  XAsset asset;
  unsigned __int8 zoneIndex;
  bool inuse;
  unsigned __int16 nextHash;
  unsigned __int16 nextOverride;
  unsigned __int16 usageFrame;
};

struct XZone
{
  unsigned __int16 index;
  int flags;
  XBlock blocks[8];
};

struct DBReorderAssetEntry
{
  unsigned int sequence;
  int type;
  const char *typeString;
  const char *assetName;
};

struct ShaderStats
{
  unsigned __int8 cost;
  unsigned __int8 ALU;
  unsigned __int8 vertex;
  unsigned __int8 texture;
  unsigned __int8 sequencer;
  unsigned __int8 interpolator;
  unsigned __int8 GPR;
  unsigned __int8 threads;
};

struct DBDecompressCmd_t
{
  int which;
  DB_LOAD_STREAM *stream;
  unsigned __int8 *ioBuffer;
  unsigned __int8 iv[8];
};

struct peerResults_t
{
  unsigned int receivedPacketCount;
  unsigned int totalLatencyMS;
  float m;
  float s;
};

struct PartyField
{
  int bits;
  int offset;
  int size;
  const char *name;
};

struct MessageLine
{
  int messageIndex;
  int textBufPos;
  int textBufSize;
  int typingStartTime;
  int lastTypingSoundTime;
  int flags;
};

struct Message
{
  int startTime;
  int endTime;
};

struct MessageWindow
{
  MessageLine *lines;
  Message *messages;
  char *circularTextBuffer;
  int textBufSize;
  int lineCount;
  int padding;
  int scrollTime;
  int fadeIn;
  int fadeOut;
  int textBufPos;
  int firstLineIndex;
  int activeLineCount;
  int messageIndex;
};

struct GfxExtraCamParms
{
  unsigned int multiExtraCamIndex;
  GfxExtraCamParms::eExtraCamRenderMode renderMode;
};

struct kbutton_t
{
  int down[2];
  unsigned int downtime;
  unsigned int msec;
  bool active;
  bool wasPressed;
  float val;
};

struct CEntityAreaParms
{
  vec3_t mins;
  vec3_t maxs;
  int contentMask;
  int *list;
  int maxCount;
  int count;
};

struct snd_weapon_shot
{
  LocalClientNum_t localClientNum;
  SndEntHandle shooter;
  Weapon weapon;
  vec3_t origin;
  vec3_t direction;
  unsigned int tagName;
  unsigned int burstCount;
  bool shooterIsPlayer;
  bool shooterIsLocalPlayer;
  bool leftGun;
  bool isLastShotInClip;
  bool isTurret;
  bool doubleTap;
  bool fakeFire;
  bool firstShotOfBurst;
};

struct WeaponOptions
{
  WeaponOptions::CamoLookup camoLookupTable[128];
  WeaponCamo *meleeCamo;
  WeaponOptions::Reticle reticles[7][64];
  const GfxImage *emblemClearTexture;
};

struct cent_field_t
{
  const char *name;
  int ofs;
  fieldtype_t type;
};

struct dynent_field_s
{
  const char *name;
  int ofs;
  fieldtype_t type;
  dynEntFieldType_t dynEntStruct;
  void (__cdecl *setter)(unsigned __int16, const dynent_field_s *);
  void (__cdecl *getter)(unsigned __int16, const dynent_field_s *);
};

struct cent_field_s
{
  const char *name;
  unsigned int constId;
  int ofs;
  int size[1];
  fieldtype_t type;
  void (__cdecl *setter)(centity_t *, const cent_field_s *);
  void (__cdecl *getter)(centity_t *, const cent_field_s *);
};

struct soundRandom_t
{
  unsigned int soundAlias;
  const char *soundName;
  vec3_t pos;
  unsigned int minWait;
  unsigned int maxWait;
  int nextPlayTime;
  soundRandom_t *next;
};

struct _lightModel_t
{
  __int16 state;
  __int16 onModelIndex;
  __int16 offModelIndex;
  unsigned int tagName;
  const FxEffectDef *fxDef;
  centity_t *pParentEnt;
  centity_t *modelEntity[1];
  int fxId[1];
};

struct _mixerLight_t
{
  centity_t *pLight[1];
  _lightParams_t lightChannel[2];
  float ltrRampTime;
  float rtlRampTime;
  bool bActive;
  int startCrossfadeTime;
  unsigned __int8 mixPos;
  float mixVal;
  void (__cdecl *pMixerLogic)(_mixerLight_t *, const cg_t *);
  float rotateTime;
  int nextRotateEndTime;
  _lightLogicParam_t p[4];
  __int16 state;
  _lightModel_t spinnerModels;
  _lightModel_t lightModels;
  int exploderID;
  unsigned __int32 bHasExploder : 1;
};

struct RumbleGraph
{
  char graphName[64];
  vec2_t knots[16];
  int knotCount;
  DevGraph devguiGraph;
  RumbleDevguiGraphInfo devguiGraphInfo;
};

struct RumbleInfo
{
  int rumbleNameIndex;
  float duration;
  float range;
  RumbleGraph *highRumbleGraph;
  RumbleGraph *lowRumbleGraph;
  int fadeWithDistance;
  int broadcast;
  const dvar_t *durationDvar;
  const dvar_t *loopDvar;
};

struct ActiveRumble
{
  const RumbleInfo *rumbleInfo;
  int startTime;
  bool loop;
  RumbleSourceType sourceType;
  ActiveRumble::<unnamed_type_source> source;
};

struct CG_PerfData
{
  int history[32];
  int count;
  int index;
  int instant;
  int total;
  float average;
  float variance;
  int min;
  int max;
};

struct cg_hudelem_t
{
  float x;
  float y;
  float rotation;
  float width;
  float height;
  char hudElemLabel[256];
  float labelWidth;
  char hudElemText[256];
  float textWidth;
  Font_s *font;
  float fontScale;
  float fontHeight;
  vec4_t color;
  int timeNow;
};

struct DelayListInfo
{
  centity_t *head;
  centity_t *latest;
  int size;
};

struct EffectFile
{
  const char *nonflesh[21][32];
  const char *flesh[21][4];
};

struct RopeGenerateVertsCmd
{
  RopeRenderInfo *ropeInfo;
  LocalClientNum_t localClientNum;
  vec3_t vieworg;
  vec3_t viewaxis[3];
};

struct CompassActor
{
  int lastUpdate;
  vec2_t lastPos;
  vec2_t lastEnemyPos;
  vec2_t satelliteEnemyPos;
  float lastYaw;
  float sattelitePingYaw;
  int pingTime;
  int beginFadeTime;
  int beginShoutCasterFadeTime;
  int beginRadarFadeTime;
  int beginSatelliteFadeTime;
  int beginStaticImageFadeTime;
  int beginVoiceFadeTime;
  unsigned int perks[2];
  unsigned __int8 needsRevive : 1;
  unsigned __int8 gpsJammerActive : 1;
  unsigned __int8 inVehicle : 1;
  unsigned __int8 enemy : 1;
  int sensorGrenadePingTime;
  float currentFadeTimeAmount;
};

struct CameraShake
{
  int time;
  float scale;
  float length;
  float radius;
  vec3_t src;
  float size;
  float rumbleScale;
};

struct punctuation_s
{
  char *p;
  int n;
  punctuation_s *next;
};

struct define_s
{
  char *name;
  int flags;
  int builtin;
  int numparms;
  token_s *parms;
  token_s *tokens;
  define_s *next;
  define_s *hashnext;
};

struct source_s
{
  char filename[64];
  char includepath[64];
  punctuation_s *punctuations;
  script_s *scriptstack;
  token_s *tokens;
  define_s *defines;
  define_s **definehash;
  indent_s *indentstack;
  int skip;
  token_s token;
};

struct AimTarget
{
  int entIndex;
  float worldDistSqr;
  vec3_t mins;
  vec3_t maxs;
  vec3_t velocity;
};

struct GfxDelayedCmdBuf
{
  int primDrawSurfPos;
  unsigned int primDrawSurfSize;
  GfxDrawSurf drawSurfKey;
};

struct GfxBspDrawSurfData
{
  GfxDelayedCmdBuf delayedCmdBuf;
  GfxDrawSurfList drawSurfList;
};

struct GfxSModelDrawSurfData
{
  GfxDelayedCmdBuf delayedCmdBuf;
  GfxDrawSurfList drawSurfList;
};

struct mnode_load_t
{
  int cellIndex;
  int planeIndex;
  unsigned int children[2];
};

struct GfxBspLoad
{
  unsigned int bspVersion;
  const dmaterial_t *diskMaterials;
  unsigned int materialCount;
  vec3_t outdoorMins;
  vec3_t outdoorMaxs;
  r_lightmapMerge_t lmapMergeInfo[32];
};

struct GfxStaticModelCombinedInst
{
  GfxStaticModelDrawInst smodelDrawInst;
  GfxStaticModelInst smodelInst;
};

struct DiskTriangleSoup
{
  unsigned __int16 materialIndex;
  unsigned __int8 lightmapIndex;
  unsigned __int8 reflectionProbeIndex;
  unsigned __int8 primaryLightIndex;
  bool hasPrimaryLightConflict;
  bool castsSunShadow;
  __int16 _unused;
  int vertexLayerData;
  unsigned int firstVertex;
  unsigned __int16 vertexCount;
  unsigned __int16 indexCount;
  int firstIndex;
};

struct CinematicInfo
{
  int id;
  void *movieHandle;
  char name[512];
  float playbackVolume;
  CIN_CALLBACK_INFO callbackInfo;
  unsigned int playbackFlags;
  CinematicFlags commonflags;
  unsigned int currentPaused;
  unsigned int targetPaused;
  int soundId;
  int nextSoundId;
  bool checkForNextSound;
  char soundAlias[256];
  MoviePlayerFunctions *moviePlayer;
  int getPathStreamId;
};

struct CinematicTextureSet
{
  GfxImage drawImageY;
  GfxImage drawImageCr;
  GfxImage drawImageCb;
  GfxImage drawImageA;
};

struct GfxCachedShaderText
{
  const char *name;
  const char *text;
  int textSize;
};

struct GfxAssembledShaderText
{
  char *string;
  unsigned int used;
  unsigned int total;
  unsigned int currentDestLine;
  bool overflowed;
  unsigned int fileCount;
  GfxAssembledShaderTextFile files[192];
};

struct GfxModelSkinnedSurface
{
  int skinnedCachedOffset;
  XSurface *xsurf;
  GfxModelSurfaceInfo info;
  GfxPackedVertex *skinnedVert;
};

struct XModelRigidCullInfoContext
{
  int cullInfoPos;
  unsigned int cullInfoBufSize;
  unsigned __int8 cullFlags;
  unsigned int size;
};

struct DpvsDynamicCellCmd
{
  unsigned int numBatches;
  DpvsDynamicCellCmd_Individual batches[6];
};

struct DpvsPlanes
{
  const DpvsPlane *planes;
  int count;
};

struct DpvsClipPlanes
{
  DpvsPlane planes[16];
  unsigned int count;
};

struct GfxCmdBufContext
{
  $1781C424A2AA8D116DC3A583246C38D6 ___u0;
};

struct GfxTrianglesDrawStream
{
  const unsigned int *primDrawSurfPos;
  unsigned int surfCount;
  const unsigned __int16 *surfList;
  const GfxTexture *reflectionProbeTexture;
  const GfxTexture *lightmapSecondaryTexture;
  unsigned int customSamplerFlags;
  GfxTexture *whiteTexture;
  GfxCmdBufContext context;
  GfxSurface *surfaces;
};

struct PerfTimerStyle
{
  Font_s *font;
  float fontWidth;
  float fontHeight;
  PerfTimerDisplayMode displayMode;
  PerfTimerDisplayType displayType;
  float (__cdecl *convertTime)(unsigned int);
  unsigned int timerCount;
  unsigned int timerNameCharCount;
  const char **timerNames;
  const GfxColor *timerColors;
  float totalBarY;
  float budgetMs;
  float budgetPixels;
  unsigned int bucketCount;
  const char **bucketNames;
};

struct PerfTimerFrameHistory
{
  unsigned int currentFrame;
  unsigned int frameCount;
  PerfTimerFrame frames[64];
};

struct GPUTimerFrame
{
  unsigned int frameIndex;
  unsigned int beginTime;
  unsigned int totalTime;
  bool isCurrent;
  GPUTimer timers[40];
};

struct ImageList
{
  unsigned int count;
  GfxImage *image[5312];
};

struct GfxImageFileHeader
{
  char tag[3];
  unsigned __int8 version;
  unsigned __int8 format;
  unsigned __int8 flags;
  __int16 dimensions[3];
  float gamma;
  unsigned __int8 maxGlossForMip[16];
  int fileSizeForPicmip[8];
};

struct PerMapMaterialTable
{
  const char *name;
  Material **material;
};

struct stream_source_info_t
{
  unsigned __int8 Stream;
  unsigned __int8 Offset;
  unsigned __int8 Type;
};

struct ScriptableConstant
{
  unsigned __int8 source;
  const char *sourceName;
  unsigned int sourceNameHash;
};

struct MtlStateMapBitName
{
  const char *name;
  int bits;
};

struct MaterialStateMapRule
{
  unsigned int stateBitsMask[2];
  unsigned int stateBitsValue[2];
  unsigned int stateBitsSet[2];
  unsigned int stateBitsClear[2];
};

struct MaterialStateMap
{
  const char *name;
  MaterialStateMapRuleSet *ruleSet[10];
};

struct _D3D11_SIGNATURE_PARAMETER_DESC
{
  const char *SemanticName;
  unsigned int SemanticIndex;
  unsigned int Register;
  D3D_NAME SystemValueType;
  D3D_REGISTER_COMPONENT_TYPE ComponentType;
  unsigned __int8 Mask;
  unsigned __int8 ReadWriteMask;
  unsigned int Stream;
};

struct ShaderArgumentSource
{
  ShaderIndexRange indexRange;
  unsigned __int16 type;
  ShaderArgumentSource::<unnamed_type_u> u;
};

struct VertexConstantMappingEntry
{
  unsigned __int8 value;
  unsigned __int8 materialType;
  VertexConstantMapping *mappingArray;
  unsigned int mappingCount;
};

struct GfxDecodedLightGridColors
{
  vec4_t rgb[56];
};

struct GfxShadowedLightHistory
{
  GfxShadowedLightEntry entries[4];
  unsigned int entryCount;
  unsigned int lastUpdateTime;
};

struct GfxCmdDrawPoints
{
  GfxCmdHeader header;
  __int16 pointCount;
  unsigned __int8 size;
  unsigned __int8 dimensions;
  GfxPointVertex verts[1];
};

struct GfxSceneParms
{
  LocalClientNum_t localClientNum;
  float blurRadius;
  float adsZScale;
  float sunVisibility;
  float rimIntensity;
  vec4_t genericSceneVector0;
  vec4_t genericSceneVector1;
  vec4_t genericSceneVector2;
  vec4_t genericSceneVector3;
  vec4_t cameraVelocity;
  GfxDepthOfField dof;
  GfxLightScale charPrimaryLightScale;
  GfxFilm film;
  GfxBloom bloom;
  GfxCompositeFx flameFx;
  GfxReviveFx reviveFx;
  GfxCompositeFx waterSheetingFx;
  GfxDoubleVision doubleVision;
  GfxGenericFilter genericFilter;
  GfxPoison poisonFx;
  GfxCompositeFx electrifiedFx;
  GfxCompositeFx transportedFx;
  GfxSaveScreenFx saveScreenFx;
  bool isRenderingFullScreen;
  bool playerTeleported;
  GfxViewport sceneViewport;
  GfxViewport displayViewport;
  GfxViewport scissorViewport;
  const GfxLight *primaryLights;
  float sceneX;
  float sceneY;
  float sceneW;
  float sceneH;
};

struct GfxDrawSurfListArgs
{
  GfxCmdBufContext context;
  unsigned int firstDrawSurfIndex;
  const GfxDrawSurfListInfo *info;
};

struct GfxRenderCommandExecState
{
  const void *cmd;
};

struct Corona
{
  bool inUse;
  GfxLightCorona *info;
  int timeSinceSpawned;
  float currentVisibility;
  float targetVisibility;
  int hitNum;
  bool wasEverVisible;
  bool queryIssued[5];
  ID3D11Query *query[5];
  ID3D11Query *queryMax[5];
};

struct CoronaState
{
  unsigned int numActive;
  unsigned int numPending;
  Corona active[16];
  Corona pending[16];
};

struct OcclusionQuery
{
  bool enabled;
  bool error;
  bool isWorldPos;
  bool isValidPos;
  vec3_t position;
  float depthBias;
  float lastVisibility;
  int localClientNum;
  int hitNum;
  bool issued[2];
  ID3D11Query *query[2];
};

