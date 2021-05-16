prefab={}
prefab[0] = {Name ="PlayerBullet_" , HowManyCmps=4,Persist=false}
prefab[1] = {Component = "Transform", Coord = {X = 10, Y = 0, Z = 0},Rotation = {X=0,Y=0,Z=0},Scale = {X=.1,Y=.1,Z=.1}}
prefab[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Red", 
			 Visible=true, Shadows=true, RenderingDistance = 1000}
prefab[3] = { Component = "RigidBody", Type="Box", Mass=1, Width=1, Depth=1, Height=1, ConstrainAngle = true,Bounciness=1,kinematic=false,IsTrigger=false}
prefab[4] = { Component = "PlayerBulletBehaviorComponent",Damage=5, MovementSpeed = 10, LifeTime= 5.0}