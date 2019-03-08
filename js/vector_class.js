//CLASS SYNTAX:
class PVector {
    constructor(x, y){
        this.x = x;
        this.y = y;
    }

    getx(){
        return(this.x);
    }
    gety(){
        return(this.y);
    }

    add(v){
        this.x += v.x;
        this.y += v.y;
    }
    sub(v){
        this.x -= v.x;
        this.y -= v.y;
    }
    mult(s){
        this.x *= s;
        this.y *= s;
    }
    div(s){
        this.x /= s;
        this.y /= s;
    }
    mag(){
        return Math.sqrt(this.x*this.x + this.y*this.y);
    }
    normalize(){
        var m = this.mag();
        if(m > 0){
            this.div(m);
        }
    }
    getsub(v){
        var t = new PVector(this.x, this.y);
        t.sub(v);
        return t;
    }
    getadd(v){
        var t = new PVector(this.x, this.y);
        t.add(v);
        return t;
    }
    getavg(v){
        var t = new PVector(this.x, this.y);
        t.add(v);
        t.div(2);
        return t;
    }
    avg(v){
        this.x = (this.x + v.x)/2;
        this.y = (this.y + v.x)/2;
    }
    getangle(){
        return Math.atan2(this.y,this.x);
    }
}

class Target extends PVector {
    constructor(x, y, radius){
        super(x,y);
        this.radius = radius;
        this.newTarget = new PVector(0,0);
        this.seedx = Math.floor(Math.random()*1000);
        this.seedy = Math.floor(Math.random()*1000);
    }
    createCircularJitter(){
        var currentLoc = new PVector(this.x, this.y);
        var seedLoc = new PVector(this.seedx,this.seedy);
        var dir = seedLoc.getsub(currentLoc);
        dir.normalize();
        dir.mult(this.radius);

        this.newTarget = currentLoc.getadd(dir);

        return this.newTarget;
    }

    doJitter(){
        var num = Math.floor(Math.random()*100);
        num *= Math.floor(Math.random()*2) == 1 ? 1 : -1; // this will add minus sign in 50% of cases
        this.seedx += num; 
        this.seedy += num; 
    }
}
