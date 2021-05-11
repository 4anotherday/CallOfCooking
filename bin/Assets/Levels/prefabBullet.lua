prefab={}
prefab[0] ={Name ="PlayerBullet_" , HowManyCmps=4,Persist=false}
prefab[1]={ Component = "Transform", Coord = {X = -150, Y = -290, Z = -100},Rotation = {X=0,Y=0,Z=0},Scale = {X=.1,Y=.1,Z=.1}}
prefab[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Red", 
			RotateAngle = 0, Rotate={X=0, Y=0, Z=0}, Scale = {X=0, Y=0, Z=0}, LookAt ={X=1, Y=1, Z=1},
			Visible=true, Shadows=true, RenderingDistance = 1000}
prefab[3] = { Component = "RigidBody", Type="Box", Mass=1, Width=40, Depth=40, Height=40, ConstrainAngle = true,Bounciness=1,kinematic=false,IsTrigger=false}
prefab[4] = { Component = "PlayerBulletBehaviorComponent",Damage=5, MovementSpeed = 1023, LifeTime= 5.0}