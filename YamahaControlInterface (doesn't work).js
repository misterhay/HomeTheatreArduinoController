{
"name": "refreshButton",
"type": "Button",
"x": 0,
"y": .85,
"width": .15,
"height": .15,
"mode": "momentary",
"color": "#000000",
"stroke": "#aaaaaa",
"ontouchstart": "interfaceManager.refreshInterface()",
},

{
 "name" : "yamahaPower",
 "type" : "Button",
 "x" : 0, "y" : 0,
 "width" : .25, "height" : .25,
 "mode" : "momentary",
 "label" : "Power",
 "min":0, "max":1,
 "address" : "/yamaha",
},

{
 "name" : "yamahaVolumeUp",
 "type" : "Button",
 "x" : 0, "y" : .30,
 "width" : .25, "height" : .25,
 "mode" : "momentary",
 "label" : "VolumeUp",
 "min":0, "max":2,
 "address" : "/yamaha",
},