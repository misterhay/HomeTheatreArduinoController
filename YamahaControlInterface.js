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
 "min":-1, "max":1,
 "address" : "yamaha",
}