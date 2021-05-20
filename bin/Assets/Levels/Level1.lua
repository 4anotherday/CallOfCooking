-- How to define game objects in the scene file
-- Step1: HowManyGameObjects must contain one more number than the last go_X that was declared because these start at 0
-- 		  If you want to add a go add one to this variable
-- Step2: Structure
--  go_Number = {}   								-> where "Number" is the next to the last go declared
--  go_Number[0] = { Name = "", HowManyCmps = X}	-> Name is the name of the GameObject. HowManyCmps is the number of components of the go
--  go_Number[1] = { Component = " ", General Data} -> Component is the ENUM used to identify the COMPONENT (getComponentType method from LuaParser). 
--													   General Data is the component data

-- You must bear in mind that in the definition of go, the first position of the array will always be the data that it needs to know its name 
-- and how many components it has. The following positions in the array will be used to define the components

-- You can find component definition examples at the end of this document

HowManyGameObjects = 53

go_0 = {}
go_0[0] = { Name = "Suelo", HowManyCmps = 3, Persist = false}
go_0[1] = { Component = "Transform", Coord = {X = 0, Y = -0.7, Z = 0},Rotation = {X=0,Y=0,Z=0},Scale = {X=13,Y=0.1,Z=13}}
go_0[2] = {	Component = "RenderObject", MeshName="suelo.mesh", Material="suelo", 
			LookAt ={X=1, Y=1, Z=1},
			Visible=true, Shadows=true, RenderingDistance = 9999}
go_0[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_1 = {}
go_1[0] = { Name = "Camera", HowManyCmps = 4, Persist = false}
go_1[1] = { Component = "Transform", Coord = {X = 0, Y = 6, Z = 0}, Rotation={X=-70, Y=0, Z=0}}
go_1[2] = { Component = "Camera", SlaveRotation = true, Plane = {Near = 1, Far = 9999},
			Projection = true, Fovy = 60, Frustrum = {Left = 1, Right = 1, Top = 1, Bot = 1}, 
			OrthoWindow = {W = 100, H = 100}, Viewport = {Left = 0, Top = 0, W = 1, H = 1},
			DisplayOverlays= true, zOrder = 1}
go_1[3] = { Component = "CameraControllerComponent",Target="Player", Offset = {X =0, Y = 4, Z = 1.5}}
go_1[4] = { Component = "AudioSource", Route = {"Assets/Audio/GameMusic.mp3"}, Stereo = true,
			MinMaxDistance = {Min = 2, Max = 6}, Volume = 0.1, Loop = -1, Stereo = false, Play = true}


go_2 = {}
go_2[0] = { Name = "DirectionalLight", HowManyCmps = 2, Persist = false}
go_2[1] = { Component = "Transform", Coord = {X = 0, Y = 20, Z = 0}, Rotation = {X = 0, Y = 0, Z = 0}}
go_2[2] = { Component = "LightComponent", LightType= "DIRECTIONAL", Visible = true,
 			Diffuse = {Red = 1, Green= 1, Blue =1}, 
 			Specular = {Red = 1, Green= 1, Blue = 1},
 			LightDirection = {X = 0.9, Y = -0.8,Z = 0},
			Intensity = 20}

go_3 = {}
go_3[0] = { Name = "Player", HowManyCmps = 8, Persist = false}
go_3[1] = { Component = "Transform", Coord = {X = 0, Y = 1, Z = 0}, Rotation = {X = 0, Y =0, Z = 0}, Scale = {X = 0.5, Y = 0.5, Z = 0.5}}
go_3[2] = {	Component = "RenderObject", MeshName="cerdo.mesh", Material= "Cerdi", Visible=true, Shadows=true, RenderingDistance = 1000}		
go_3[3] = { Component = "RigidBody", Type="Box", Mass=1, ConstrainAngle = true, Bounciness = 1}
go_3[4] = { Component = "PlayerMovementComponent", Speed=150, RotationSpeed=1}
go_3[5] = { Component = "PlayerHealthComponent", Lives=3, MaxLife=3}
go_3[6] = { Component = "PlayerShootComponent", Damage=1, Cadence=0.4}
go_3[7] = { Component = "PlayerBulletPoolComponent", MaxPool = 30, Path = "Assets/Levels/prefabBullet.lua",
			RespawnPositions={{10,25,30},{25,50,60},{35,40,40}}}
go_3[8] = { Component = "AudioSource", Route = {"Assets/Audio/damagePlayeer.mp3", "Assets/Audio/shootPlayer.mp3"}, Stereo = true,
			MinMaxDistance = {Min = 2, Max = 6}, Volume = 0.1, Loop = 0, Stereo = false, Play = false}

go_4={}
go_4[0] = { Name ="ParedIzq" , HowManyCmps=3,Persist=false}
go_4[1] = { Component = "Transform", Coord = {X = -5.5, Y = -0.6, Z = 0},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_4[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_4[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_5={}
go_5[0] = { Name ="ParedDer" , HowManyCmps=3,Persist=false}
go_5[1] = { Component = "Transform", Coord = {X = 5.55, Y = -0.6, Z = 0},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_5[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_5[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_6={}
go_6[0] = { Name ="ParedArr" , HowManyCmps=3,Persist=false}
go_6[1] = { Component = "Transform", Coord = {X = 0, Y = -0.6, Z = -5.14},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_6[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_6[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_7={}
go_7[0] = { Name ="ParedAb" , HowManyCmps=3,Persist=false}
go_7[1] = {Component = "Transform", Coord = {X = 0, Y = -0.6, Z = 5.32},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_7[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_7[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_8={}
go_8[0] = { Name="GameManager", HowManyCmps=7, Persist = false}
go_8[1] = { Component = "LevelManagerComponent", CurrentLevel=0, Path = "Assets/Levels/levelManagerInfo.lua"}
go_8[2] = { Component = "ScoreManagerComponent", Score = 0, MaxScore = 0, ComboTime = 2 }
go_8[3] = { Component = "GranadePoolComponent", MaxPool = 10, Path = "Assets/Levels/prefabGrenade.lua"}
go_8[4] = { Component = "GranadeBulletPoolComponent", MaxPool = 10, Path = "Assets/Levels/prefabGrenadeBullet.lua"}
go_8[5] = { Component = "LemonPoolComponent", MaxPool = 10, Path = "Assets/Levels/prefabLemon.lua"}
go_8[6] = { Component = "WatermelonPoolComponent", MaxPool = 13, Path = "Assets/Levels/prefabWatermelon.lua"}
go_8[7] = { Component = "CardSystemComponent", MaxPool = 5, AttackCardPrefab = "Assets/Levels/prefabCardAttack.lua",  LifeCardPrefab = "Assets/Levels/prefabCardLife.lua", 
			MovSpeedCardPrefab = "Assets/Levels/prefabCardSpeedMov.lua"}

go_9={}
go_9[0] = {Name="UIManager", HowManyCmps=3, Persist = false}
go_9[1]=  {Component = "Transform"}
go_9[2] = {Component = "UIManagerComponent"}
go_9[3] = {Component = "OverlayComponent", Name = "GameUI", Hide = false}

go_10 = {}
go_10[0] = { Name = "PlayerAttackHitBox", HowManyCmps = 4, Persist = false}
go_10[1] = { Component = "Transform", Coord = {X = 0.5, Y = 2, Z = 0},Rotation = {X=0,Y=0,Z=0},Scale = {X=0.1,Y=0.1,Z=.1}}
go_10[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Red", 
			Visible=true, Shadows=true, RenderingDistance = 9999}
go_10[3] = { Component = "SphereCollider", Radius=1, IsTrigger=true}
go_10[4] = { Component = "PlayerAttackComponent", Damage = 1,AtackRate = 2,AttackHitBoxDistance = 0.35, PlayerRange = 1}

go_11 = {}
go_11[0] = { Name = "RestartButton", HowManyCmps = 3, Persist = false}
go_11[1] = { Component = "Transform"}
go_11[2] = { Component = "ButtonComponent", Active = true, OverLayName="GameUI", ContainerName= "GameUI/RestartGame", 
			DefaultMaterial = "CallOfCooking/Button", HoverMaterial = "CallOfCooking/ButtonHover", PressMaterial = "CallOfCooking/ButtonPress"}
go_11[3] = { Component = "RestartGameButtonComponent"}
go_11[4] = { Component = "AudioSource", Route = {"Assets/Audio/button.mp3"}, Stereo = true,
			MinMaxDistance = {Min = 2, Max = 6}, Volume = 0.1, Loop = 0, Stereo = false, Play = true}

go_12 = {}
go_12[0] = { Name = "QuitButton", HowManyCmps = 4, Persist = false}
go_12[1] = { Component = "Transform"}
go_12[2] = { Component = "ButtonComponent", Active = true, OverLayName="GameUI", ContainerName= "GameUI/QuitGame", 
			DefaultMaterial = "CallOfCooking/Button", HoverMaterial = "CallOfCooking/ButtonHover", PressMaterial = "CallOfCooking/ButtonPress"}
go_12[3] = { Component = "QuitEndGameButtonComponent"}
go_12[4] = { Component = "AudioSource", Route = {"Assets/Audio/button.mp3"}, Stereo = true,
			MinMaxDistance = {Min = 2, Max = 6}, Volume = 0.1, Loop = 0, Stereo = false, Play = true}

--//-------------------------------PARED IZQUIERDA-----------------------------------
go_13={}
go_13[0] = { Name ="ParedIzq2" , HowManyCmps=3,Persist=false}
go_13[1] = { Component = "Transform", Coord = {X = -5.5, Y = -0.6, Z = -1},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_13[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_13[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_14={}
go_14[0] = { Name ="ParedIzq3" , HowManyCmps=3,Persist=false}
go_14[1] = { Component = "Transform", Coord = {X = -5.5, Y = -0.6, Z = -2},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_14[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_14[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_15={}
go_15[0] = { Name ="ParedIzq4" , HowManyCmps=3,Persist=false}
go_15[1] = { Component = "Transform", Coord = {X = -5.5, Y = -0.6, Z = -3},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_15[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_15[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_16={}
go_16[0] = { Name ="ParedIzq5" , HowManyCmps=3,Persist=false}
go_16[1] = { Component = "Transform", Coord = {X = -5.5, Y = -0.6, Z = -4},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_16[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_16[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_17={}
go_17[0] = { Name ="ParedIzq6" , HowManyCmps=3,Persist=false}
go_17[1] = { Component = "Transform", Coord = {X = -5.5, Y = -0.6, Z = -5},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_17[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_17[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_18={}
go_18[0] = { Name ="ParedIzq7" , HowManyCmps=3,Persist=false}
go_18[1] = { Component = "Transform", Coord = {X = -5.5, Y = -0.6, Z = 1},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_18[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_18[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_19={}
go_19[0] = { Name ="ParedIzq8" , HowManyCmps=3,Persist=false}
go_19[1] = { Component = "Transform", Coord = {X = -5.5, Y = -0.6, Z = 2},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_19[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_19[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_20={}
go_20[0] = { Name ="ParedIzq9" , HowManyCmps=3,Persist=false}
go_20[1] = { Component = "Transform", Coord = {X = -5.5, Y = -0.6, Z = 3},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_20[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_20[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_21={}
go_21[0] = { Name ="ParedIzq10" , HowManyCmps=3,Persist=false}
go_21[1] = { Component = "Transform", Coord = {X = -5.5, Y = -0.6, Z = 4},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_21[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_21[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_22={}
go_22[0] = { Name ="ParedIzq11" , HowManyCmps=3,Persist=false}
go_22[1] = { Component = "Transform", Coord = {X = -5.5, Y = -0.6, Z = 5},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_22[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_22[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

--//-------------------------------PARED DERECHA-----------------------------------
go_23={}
go_23[0] = { Name ="ParedDer2" , HowManyCmps=3,Persist=false}
go_23[1] = { Component = "Transform", Coord = {X = 5.5, Y = -0.6, Z = -1},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_23[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_23[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_24={}
go_24[0] = { Name ="ParedDer3" , HowManyCmps=3,Persist=false}
go_24[1] = { Component = "Transform", Coord = {X = 5.5, Y = -0.6, Z = -2},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_24[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_24[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_25={}
go_25[0] = { Name ="ParedDer4" , HowManyCmps=3,Persist=false}
go_25[1] = { Component = "Transform", Coord = {X = 5.5, Y = -0.6, Z = -3},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_25[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_25[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_26={}
go_26[0] = { Name ="ParedDer5" , HowManyCmps=3,Persist=false}
go_26[1] = { Component = "Transform", Coord = {X = 5.5, Y = -0.6, Z = -4},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_26[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_26[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_27={}
go_27[0] = { Name ="ParedDer6" , HowManyCmps=3,Persist=false}
go_27[1] = { Component = "Transform", Coord = {X = 5.5, Y = -0.6, Z = -5},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_27[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_27[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_28={}
go_28[0] = { Name ="ParedDer7" , HowManyCmps=3,Persist=false}
go_28[1] = { Component = "Transform", Coord = {X = 5.5, Y = -0.6, Z = 1},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_28[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_28[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_29={}
go_29[0] = { Name ="ParedDer8" , HowManyCmps=3,Persist=false}
go_29[1] = { Component = "Transform", Coord = {X = 5.5, Y = -0.6, Z = 2},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_29[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_29[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_30={}
go_30[0] = { Name ="ParedDer9" , HowManyCmps=3,Persist=false}
go_30[1] = { Component = "Transform", Coord = {X = 5.5, Y = -0.6, Z = 3},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_30[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_30[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_31={}
go_31[0] = { Name ="ParedDer10" , HowManyCmps=3,Persist=false}
go_31[1] = { Component = "Transform", Coord = {X = 5.5, Y = -0.6, Z = 4},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_31[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_31[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_32={}
go_32[0] = { Name ="ParedDer11" , HowManyCmps=3,Persist=false}
go_32[1] = { Component = "Transform", Coord = {X = 5.5, Y = -0.6, Z = 5},Rotation = {X=0,Y=0,Z=0},Scale = {X=1,Y=1,Z=1}}
go_32[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_32[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

--//-------------------------------PARED ARRIBA-----------------------------------
go_33={}
go_33[0] = { Name ="ParedArr2" , HowManyCmps=3,Persist=false}
go_33[1] = { Component = "Transform", Coord = {X = 1, Y = -0.6, Z = -5.14},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_33[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_33[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_34={}
go_34[0] = { Name ="ParedArr3" , HowManyCmps=3,Persist=false}
go_34[1] = { Component = "Transform", Coord = {X = 2, Y = -0.6, Z = -5.14},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_34[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_34[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_35={}
go_35[0] = { Name ="ParedArr4" , HowManyCmps=3,Persist=false}
go_35[1] = { Component = "Transform", Coord = {X = 3, Y = -0.6, Z = -5.14},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_35[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_35[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_36={}
go_36[0] = { Name ="ParedArr5" , HowManyCmps=3,Persist=false}
go_36[1] = { Component = "Transform", Coord = {X = 4, Y = -0.6, Z = -5.14},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_36[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_36[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_37={}
go_37[0] = { Name ="ParedArr6" , HowManyCmps=3,Persist=false}
go_37[1] = { Component = "Transform", Coord = {X = 5, Y = -0.6, Z = -5.14},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_37[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_37[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_38={}
go_38[0] = { Name ="ParedArr7" , HowManyCmps=3,Persist=false}
go_38[1] = { Component = "Transform", Coord = {X = -5, Y = -0.6, Z = -5.14},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_38[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_38[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_39={}
go_39[0] = { Name ="ParedArr8" , HowManyCmps=3,Persist=false}
go_39[1] = { Component = "Transform", Coord = {X = -1, Y = -0.6, Z = -5.14},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_39[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_39[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_40={}
go_40[0] = { Name ="ParedArr9" , HowManyCmps=3,Persist=false}
go_40[1] = { Component = "Transform", Coord = {X = -2, Y = -0.6, Z = -5.14},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_40[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_40[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_41={}
go_41[0] = { Name ="ParedArr10" , HowManyCmps=3,Persist=false}
go_41[1] = { Component = "Transform", Coord = {X = -3, Y = -0.6, Z = -5.14},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_41[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_41[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_42={}
go_42[0] = { Name ="ParedArr11" , HowManyCmps=3,Persist=false}
go_42[1] = { Component = "Transform", Coord = {X = -4, Y = -0.6, Z = -5.14},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_42[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_42[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

--//-------------------------------PARED ABAJO-----------------------------------
go_43={}
go_43[0] = { Name ="ParedAb2" , HowManyCmps=3,Persist=false}
go_43[1] = { Component = "Transform", Coord = {X = 1, Y = -0.6, Z = 5.32},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_43[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_43[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_44={}
go_44[0] = { Name ="ParedAb3" , HowManyCmps=3,Persist=false}
go_44[1] = { Component = "Transform", Coord = {X = 2, Y = -0.6, Z = 5.32},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_44[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_44[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_45={}
go_45[0] = { Name ="ParedAb4" , HowManyCmps=3,Persist=false}
go_45[1] = { Component = "Transform", Coord = {X = 3, Y = -0.6, Z = 5.32},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_45[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_45[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_46={}
go_46[0] = { Name ="ParedAb5" , HowManyCmps=3,Persist=false}
go_46[1] = { Component = "Transform", Coord = {X = 4, Y = -0.6, Z = 5.32},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_46[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_46[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_47={}
go_47[0] = { Name ="ParedAb6" , HowManyCmps=3,Persist=false}
go_47[1] = { Component = "Transform", Coord = {X = 5, Y = -0.6, Z = 5.32},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_47[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_47[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_48={}
go_48[0] = { Name ="ParedAb7" , HowManyCmps=3,Persist=false}
go_48[1] = { Component = "Transform", Coord = {X = -5, Y = -0.6, Z = 5.32},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_48[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_48[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_49={}
go_49[0] = { Name ="ParedAb8" , HowManyCmps=3,Persist=false}
go_49[1] = { Component = "Transform", Coord = {X = -1, Y = -0.6, Z = 5.32},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_49[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_49[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_50={}
go_50[0] = { Name ="ParedAb9" , HowManyCmps=3,Persist=false}
go_50[1] = { Component = "Transform", Coord = {X = -2, Y = -0.6, Z = 5.32},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_50[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_50[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_51={}
go_51[0] = { Name ="ParedAb10" , HowManyCmps=3,Persist=false}
go_51[1] = { Component = "Transform", Coord = {X = -3, Y = -0.6, Z = 5.32},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_51[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_51[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

go_52={}
go_52[0] = { Name ="ParedAb11" , HowManyCmps=3,Persist=false}
go_52[1] = { Component = "Transform", Coord = {X = -4, Y = -0.6, Z = 5.27},Rotation = {X=0,Y=90,Z=0},Scale = {X=1,Y=1,Z=1}}
go_52[2] = {	Component = "RenderObject", MeshName="valla.mesh", Material="LogBody", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_52[3] = { Component = "RigidBody", Type="Box",Static=true,Width=1,Depth=1,Height=1}

--go_8={}
--go_8[0] ={Name ="Enemy" , HowManyCmps=5,Persist=false}
--go_8[1]={ Component = "Transform", Coord = {X = 100, Y = -200, Z = 0},Rotation = {X=1,Y=1,Z=1},Scale = {X=.3,Y=.3,Z=.3}}
--go_8[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Red", 
--			RotateAngle = 0, Rotate={X=0, Y=0, Z=0}, Scale = {X=0, Y=0, Z=0}, LookAt ={X=1, Y=1, Z=1},
--			Visible=true, Shadows=true, RenderingDistance = 1000}
--go_8[3] = { Component = "RigidBody", Type="Box",Mass=9,Width=40,Depth=40,Height=100}
--go_8[4] = { Component = "GrenadeBehaviorComponent", Range=100,AttackSpeed=2, MovementSpeed = 1}
--go_8[5] = { Component = "EnemyHealthComponent", Points=100,HitPoints=2}


--go_8={}
--go_8[0] ={Name ="Bala" , HowManyCmps=4,Persist=false}
--go_8[1]={ Component = "Transform", Coord = {X = 100, Y = -200, Z = -100},Rotation = {X=1,Y=1,Z=1},Scale = {X=.3,Y=.3,Z=.3}}
--go_8[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Fucsia", 
--			RotateAngle = 0, Rotate={X=0, Y=0, Z=0}, Scale = {X=0, Y=0, Z=0}, LookAt ={X=1, Y=1, Z=1},
--			Visible=true, Shadows=true, RenderingDistance = 1000}
--go_8[3] = { Component = "RigidBody", Type="Box",Mass=0,Width=40,Depth=40,Height=100}
--go_8[4] = { Component = "PlayerBulletBehaviorComponent",Damage=5, MovementSpeed = 20}


-- go_5={}
-- go_5[0] ={Name ="Granato" , HowManyCmps=4,Persist=false}
-- go_5[1]={ Component = "Transform", Coord = {X = 300, Y = -200, Z = 150},Rotation = {X=0,Y=0,Z=0},Scale = {X=.3,Y=.3,Z=.3}}
-- go_5[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Red", 
-- 			RotateAngle = 0, Rotate={X=0, Y=0, Z=0}, Scale = {X=0, Y=0, Z=0}, LookAt ={X=1, Y=1, Z=1},
-- 			Visible=true, Shadows=true, RenderingDistance = 1000}
-- go_5[3] = { Component = "RigidBody", Type="Box",Mass=9,Width=40,Depth=40,Height=100}
-- go_5[4] = { Component = "GrenadeBehaviorComponent", Range=2,AttackSpeed=2, MovementSpeed = 1}

-- go_3 = {}
-- go_3[0] = { Name = "ImageR", HowManyCmps = 2, Persist = false}
-- go_3[1] = { Component = "Transform", Coord = {X = 0, Y = 0, Z = 0}}
-- go_3[2] = { Component = "ImageRenderer", DefaultDimension = {W = 1, H = 2}, 
-- 			MaterialName = "Practica1/Yellow", Visible = true, 
-- 			BillboardOrigin = "BBO_TOP_LEFT", BillboardType = "BBT_POINT",
-- 			BillboardRotationType = "BBR_VERTEX",
-- 			Scale = {X = 1, Y = 1, Z = 1}, Rotation = {X = 1, Y = 2, Z = 3, Angle = 0}}
-- go_3 = {}
-- go_3[0] = { Name = "Cam", HowManyCmps = 2, Persist = false}
-- go_3[1] = { Component = "Transform", Coord = {X = 400, Y = 80, Z = 0}}
-- go_3[2] = { Component = "Camera", Orientation = {X = 0, Y = 0, Z = -1}, Plane = {Near = 1, Far = 9999},
-- 			Projection = true, Fovy = 6, Frustrum = {Left = 4, Right = 3, Top = 2, Bot = 1}, 
-- 			OrthoWindow = {W = 8, H = 9}, Viewport = {Left = 0.5, Top = 0, W = 0.5, H = 1},
-- 			DisplayOverlays= true, zOrder = 2}


-- COMPONENT EXAMPLES

-- Transform 		-> go_goNumber[componentNumber] = { Component = "Transform", Coord = {X = 1, Y = 1, Z = 1}}

-- AudioSource 		-> go_goNumber[componentNumber] = { Component = "AudioSource", Route = "./src"}

-- LightComponent	-> go_goNumber[componentNumber] = { Component = "LightComponent", LightType= "POINT", Visible = false,
--														Diffuse = {Red = 1, Green= 1, Blue = 1} 
--														Specular = {Red = 1, Green= 1, Blue = 1}
--														Attenuation = {Range = 1, Constant = 1, Linear = 1, Quadratic = 1}
--														SpotLightRange = {InnerAngle = 1, OuterAngle = 1, FallOf = 1}}

-- ListenerComponent-> go_goNumber[componentNumber] = { Component = "Listener", ListenerNumber = 0, 
--														Velocity = {X = 1, Y = 0, Z = 5}, Forward = {X = 3, Y = 2, Z = 1}, Up = {X = 8, Y = 7, Z = 9}}

-- AnimatorComponent-> go_goNumber[componentNumber] = { Component = "Animator", HowManyStates = 2,
--														State1 = {Name = "initial", Loop = true},
--														State2 = {Name = "second", Loop = false},
--														StateN = {Name = "anotherOne", Loop = "true"}}

-- ButtonComponent	-> go_goNumber[componentNumber] = { Component = "ButtonComponent", Active = false, OverLayName="ovName", ContainerName= "SexyContainer", 
--														DefaultMaterial = "defaultMaterial", HoverMaterial = "hoverMaterial", PressMaterial = "pressMaterial"}

-- CameraComponent  -> go_goNumber[componentNumber] = { Component = "Camera", Orientation = {X = 3, Y = 2, Z = 1}, 
--    Projection (F = orthographic, T = perspective)	Plane = {Near = 2, Far = 9999}, Projection = true, Fovy = 6, 
--								 						Frustrum = {Left = 4, Right = 3, Top = 2, Bot = 1}, 
--								 						OrthoWindow = {W = 8, H = 9}, Viewport = {Left = 9, Top = 8, W = 7, H = 6}}

-- Overlay 			-> go_goNumber[componentNumber] = { Component = "OverlayComponent", Hide=true, Name = "SexyOverlay", Container = "SexyContainer", Material= "SexyOverlaymMaterial"}

-- RenderObject 	-> go_goNumber[componentNumber] = { Component = "RenderObject", MeshName="SexyMesh", Material="SexyMaterial", 
--														RotateAngle = 1, Rotate={X=1, Y=1, Z=1}, Scale = {X=1, Y=1, Z=1}, LookAt ={X=1, Y=1, Z=1},
--														Visible=false, Shadows=false, RenderingDistance = 1}

-- ImageRender      -> go_goNumber[componentNumber] = { Component = "ImageRenderer", DefaultDimension = {W = 1, H = 2}, 
--														MaterialName = "SoyFeo", Visible = false, 
--														BillboardOrigin = "BBO_TOP_LEFT", BillboardType = "BBT_POINT",
--														BillboardRotationType = "BBR_VERTEX",
--														Scale = {X = 0.3, Y = 0.5, Z = 1}, Rotation = {X = 1, Y = 2, Z = 3, Angle = 180}}

-- PartycleSystem 	-> go_goNumber[componentNumber] = { Component = "ParticleSystem", Path="SexyPath"}

-- RigidBody with Spere collider -> go_goNumber[componentNumber] = { Component = "RigidBody", Radius=5 }
