prefab={}
prefab[0] = {Name ="PlayerBullet_" , HowManyCmps=4,Persist=false}
prefab[1] = {Component = "Transform", Coord = {X = 10, Y = 0, Z = 0},Rotation = {X=0,Y=0,Z=0},Scale = {X=.1,Y=.1,Z=.1}}
prefab[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Red", 
			 Visible=true, Shadows=true, RenderingDistance = 1000}
prefab[3] = { Component = "SphereCollider", Radius=0.1, IsTrigger=true}
prefab[4] = { Component = "PlayerBulletBehaviorComponent",Damage=5, MovementSpeed = 3, LifeTime= 5.0}