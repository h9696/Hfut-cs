$fa = 1;
$fs = 0.4;

// 车身主体
color("red") {
    cube([60, 20, 10], center = true);
    translate([5, 0, 10 - 0.001])
        cube([30, 20, 10], center = true);
}



// 车轮
color("black") {
    translate([-20, -15, 0])
        rotate([90, 0, 0])
        cylinder(h = 3, r = 8, center = true);
    translate([-20, 15, 0])
        rotate([90, 0, 0])
        cylinder(h = 3, r = 8, center = true);
    translate([20, -15, 0])
        rotate([90, 0, 0])
        cylinder(h = 3, r = 8, center = true);
    translate([20, 15, 0])
        rotate([90, 0, 0])
        cylinder(h = 3, r = 8, center = true);
}

// 车轴
color("silver") {
    translate([-20, 0, 0])
        rotate([90, 0, 0])
        cylinder(h = 30, r = 2, center = true);
    translate([20, 0, 0])
        rotate([90, 0, 0])
        cylinder(h = 30, r = 2, center = true);
}

// 车灯
color("yellow") {
    translate([29, -5, 5])
        sphere(r = 3, $fn = 20);
    translate([29, 5, 5])
        sphere(r = 3, $fn = 20);
}

// 车牌
color("white") {
    translate([-30, 0, 2])
        cube([1, 10, 1], center = true);
}    