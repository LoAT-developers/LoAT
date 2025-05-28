let {view, move, fade_in, fade_out, toggle_logo, invert, change_view, start, align_vertically, align_horizontally, set_color} = window.preji;

var title = view("title").set_scale(1.2);
var svg = view("svg");
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
var his = view("history");
var accel = view("accel");
var accel_ex = view("accel-ex");
var meter = view("meter");
var meter_ex1 = view("meter-ex1").set_scale(1.4);
var meter_ex2 = view("meter-ex2").set_scale(1.4);
var gen = view("gen");
var qe = view("qe");
var qe_cad = view("qe-cad").set_scale(1.4);
var future = view("future").set_scale(1.8);
var aprove = view("aprove");
 
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
            "his-line",
            "accel",
            "accel1",
            "accel2",
            "accel3",
            "accel4",
            "accel5",
            "accel6",
            "accel7",
            "accel-ex",
            "accel-arrow",
            "accel-accelerated",
            "meter",
            "meter-def",
            "rank-def",
            "rf2",
            "meter-pros",
            "meter-pro1",
            "meter-pro2",
            "meter-cons",
            "meter-con1",
            "meter-con2",
            "meter-loop",
            "meter-ex1",
            "meter-ex1-arrow",
            "meter-ex1-mf",
            "meter-con3",
            "meter-ex2",
            "meter-ex2-arrow",
            "meter-ex2-mf",
            "gen",
            "gen1",
            "gen2",
            "gen3",
            "gen4",
            "gen5",
            "gen-ex",
            "gen-ex-arrow",
            "gen-ex-accelerated",
            "qe",
            "qe1",
            "qe3",
            "qe4",
            "qe5",
            "qe-cad",
            "qe-cad1",
            "qe-cad2",
            "future",
            "future1",
            "future2",
            "future3",
            "future4",
            "future5",
            "future6",
            "aprove",
            "aprove1",
            "aprove2",
            "aprove3",
            "aprove4",
            "aprove5",
            "aprove6",
            "aprove7",
        ], duration=0),
        move("meter-loop2", "meter-loop"),
        move("rf2", "rf1"),
    ],
    [change_view(title, delay=0, slowdown=0)],
    [change_view(svg)],

    [change_view(accel), fade_in(["accel"])],
    [fade_in(["accel1"])],
    [fade_in(["accel-ex"])],
    [fade_in(["accel2"])],
    [fade_in(["accel-arrow", "accel-accelerated"])],
    [fade_in(["accel3"])],
    [fade_in(["accel4"])],
    [fade_in(["accel5"])],
    [fade_in(["accel6"])],
    [fade_in(["accel7"])],
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
    [change_view(svg)],

    [change_view(meter), fade_in(["meter"])],
    [fade_in(["meter-def"])],
    [fade_in(["rank-def"])],
    [fade_out(["rf1"]), fade_in(["rf2"])],
    [fade_in(["meter-pros"])],
    [fade_in(["meter-pro1"])],
    [fade_in(["meter-pro2"])],
    [fade_in(["meter-cons"])],
    [fade_in(["meter-con1"])],
    [fade_in(["meter-con2"])],
    [change_view(meter_ex1), fade_in(["meter-ex1"])],
    [fade_out(["meter-loop2"]), fade_in(["meter-loop"])],
    [fade_in(["meter-ex1-arrow", "meter-ex1-mf"])],
    [change_view(meter)],
    [fade_in(["meter-con3"])],
    [change_view(meter_ex2), fade_in(["meter-ex2"])],
    [fade_in(["meter-ex2-arrow", "meter-ex2-mf"])],
    [change_view(meter)],
    [change_view(svg)],

    [change_view(gen), fade_in(["gen"])],
    [fade_in(["gen1"])],
    [fade_in(["gen-ex"])],
    [fade_in(["gen2"])],
    [fade_in(["gen-ex-arrow", "gen-ex-accelerated"])],
    [fade_in(["gen3"])],
    [fade_in(["gen4"])],
    [fade_in(["gen5"])],
    [change_view(svg)],

    [change_view(qe), fade_in(["qe"])],
    [fade_in(["qe1"])],
    [fade_in(["qe3"])],
    [change_view(qe_cad), fade_in(["qe-cad"])],
    [fade_in(["qe-cad1"])],
    [fade_in(["qe-cad2"])],
    [change_view(qe)],
    [fade_in(["qe4"])],
    [fade_in(["qe5"])],
    [change_view(svg)],

    [change_view(future), fade_in(["future"])],
    [fade_in(["future1"])],
    [fade_in(["future2"])],
    [fade_in(["future3"])],
    [fade_in(["future4"])],
    [fade_in(["future5"])],
    [fade_in(["future6"])],

    [change_view(aprove), fade_in(["aprove"], delay=4000)],
    [fade_in(["aprove1"])],
    [fade_in(["aprove2"])],
    [fade_in(["aprove3"])],
    [fade_in(["aprove4"])],
    [fade_in(["aprove5"])],
    [fade_in(["aprove6"])],
    [fade_in(["aprove7"])],
    [change_view(svg)],
];

// start the presentation
start(slides);
