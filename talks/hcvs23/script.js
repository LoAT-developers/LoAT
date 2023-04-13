let {view, move, fade_in, fade_out, toggle_logo, invert, change_view, start, align_vertically, align_horizontally, set_color} = window.preji;

var title = view("title").set_scale(1.2);
var svg = view("svg");
var intro = view("intro").set_scale(1.3);
var his_frame1 = view("his-frame1");
var his_frame2 = view("his-frame2");
var his_frame3 = view("his-frame3");
var his_frame4 = view("his-frame4");
var his_frame5 = view("his-frame5");
var his_frame6 = view("his-frame6");
var his_frame7 = view("his-frame7");
var his_frame8 = view("his-frame8");
var his_frame9 = view("his-frame9");
var his_frame10 = view("his-frame10");
var his_frame11 = view("his-frame11");
var his_frame12 = view("his-frame12");
var his_frame13 = view("his-frame13");
var his = view("history");
var aims = view("aims").set_scale(1.3);
var devel = view("devel").set_scale(1.3);
var term = view("term").set_scale(1.3);
 
var slides = [
    [
        fade_out([
            "history",
            "his-frame1",
            "his-frame2",
            "his-frame3",
            "his-frame4",
            "his-frame5",
            "his-frame6",
            "his-frame7",
            "his-frame8",
            "his-frame9",
            "his-frame10",
            "his-frame11",
            "his-frame12",
            "his-frame13",
            "his1",
            "his2",
            "his3",
            "his4",
            "his5",
            "his6",
            "his7",
            "his8",
            "his9",
            "his10",
            "his11",
            "his12",
            "his13",
            "his-line",
            "intro",
            "intro1",
            "intro2",
            "intro3",
            "intro4",
            "intro5",
            "intro6",
            "intro7",
            "intro8",
            "intro9",
            "intro10",
            "intro11",
            "aims",
            "aims1",
            "aims2",
            "aims3",
            "aims4",
            "aims5",
            "aims6",
            "aims7",
            "aims8",
            "aims9",
            "aims10",
            "devel",
            "sat",
            "sat1",
            "sat2",
            "sat3",
            "mba",
            "mba1",
            "mba2",
            "mba3",
            "mba4",
            "theories",
            "theories1",
            "theories2",
            "theories3",
            "nonlinear",
            "term",
        ], duration=0),
    ],
    [change_view(title, delay=0, slowdown=0)],
    [change_view(svg)],

    [change_view(intro), fade_in(["intro"])],
    [fade_in(["intro1"])],
    [fade_in(["intro2"])],
    [fade_in(["intro3"])],
    [fade_in(["intro4"])],
    [fade_in(["intro5"])],
    [fade_in(["intro6"])],
    [fade_in(["intro7"])],
    [fade_in(["intro8"])],
    [fade_in(["intro9"])],
    [fade_in(["intro10"])],
    [fade_in(["intro11"])],
    [change_view(svg)],
    
    [change_view(his_frame1, delay=0), fade_in(["history"]), fade_in(["his1"], delay=1500)],
    [change_view(his_frame2, delay=0), fade_in(["his2"], delay=1500)],
    [change_view(his_frame3, delay=0), fade_in(["his3"], delay=1500)],
    [change_view(his_frame4, delay=0), fade_in(["his4"], delay=1500)],
    [change_view(his_frame5, delay=0), fade_in(["his5"], delay=1500)],
    [change_view(his_frame6, delay=0), fade_in(["his6"], delay=1500)],
    [change_view(his_frame7, delay=0), fade_in(["his7"], delay=1500)],
    [change_view(his_frame8, delay=0), fade_in(["his8"], delay=1500)],
    [change_view(his_frame9, delay=0), fade_in(["his9"], delay=1500)],
    [change_view(his_frame10, delay=0), fade_in(["his10"], delay=1500)],
    [change_view(his_frame11, delay=0), fade_in(["his11"], delay=1500)],
    [change_view(his_frame12, delay=0), fade_in(["his12"], delay=1500)],
    [change_view(his_frame13, delay=0), fade_in(["his13"], delay=1500)],
    [change_view(svg)],

    [change_view(aims), fade_in(["aims"])],
    [fade_in(["aims1"])],
    [fade_in(["aims2"])],
    [fade_in(["aims3"])],
    [fade_in(["aims4"])],
    [fade_in(["aims5"])],
    [fade_in(["aims6"])],
    [fade_in(["aims7"])],
    [fade_in(["aims8"])],
    [fade_in(["aims9"])],
    [fade_in(["aims10"])],
    [change_view(svg)],

    [change_view(devel), fade_in(["devel"])],
    [fade_in(["sat", "sat1"])],
    [fade_in(["sat2"])],
    [fade_in(["sat3"])],
    [fade_in(["mba", "mba1"])],
    [fade_in(["mba2"])],
    [fade_in(["mba3"])],
    [fade_in(["mba4"])],
    [fade_in(["theories", "theories1"])],
    [fade_in(["theories2"])],
    [fade_in(["theories3"])],
    [fade_in(["nonlinear"])],
    [change_view(svg)],

    [change_view(term), fade_in(["term"])],
    [change_view(svg)],
];

// start the presentation
start(slides);
