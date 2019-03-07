window.onload = function(){
    var canvas = document.getElementById("canvas"),
        context = canvas.getContext("2d"),
        width = canvas.width = window.innerWidth,
        height = canvas.height = window.innerHeight,
        centre, mouse, origin, dir, text, angle;

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
    
    init();
    globalRender();
    
    function init() {
        centre = new PVector(300,200);
        mouse = new PVector(0,0);
        origin = new PVector(50,50);
        text = new PVector(centre.x, centre.y);
        text.avg(mouse);
    }

    function globalRender() {


        dir = mouse.getsub(centre);
        //dir.normalize();
        //dir.mult(50);
        
        
        //Animating:
        context.clearRect(0,0,width,height);
        context.beginPath();
        context.arc(centre.getx(), centre.gety(), 15, 0, Math.PI*2);
        context.fillStyle = '#0000FF';
        context.fill();
        context.beginPath();
        context.arc(mouse.getx(), mouse.gety(), 15, 0, Math.PI*2);
        context.fillStyle = '#FF0000';
        context.fill();

        context.lineWidth = 2;
        //(0,0) to mouse
        context.beginPath();
        context.strokeStyle = "red";
        context.moveTo(0,0);
        context.lineTo(mouse.x, mouse.y);
        context.stroke();

        //0,0 to centre
        context.beginPath();
        context.strokeStyle = "blue";
        context.moveTo(0,0);
        context.lineTo(centre.x, centre.y);
        context.stroke();

        
        //dir
        context.beginPath();
        context.strokeStyle = "black";
        context.moveTo(centre.x,centre.y);
        context.lineTo(centre.x + dir.x, centre.y + dir.y);

        angle = -dir.getangle();
        console.log(angle);
        
        context.save();
        //Matrix transormation to draw arrow head:
        context.transform(Math.cos(angle), -Math.sin(angle), Math.sin(angle), Math.cos(angle), centre.x + dir.x, centre.y + dir.y);

        context.moveTo(0,0);
        context.lineTo(-15, 15);
        context.moveTo(0,0);
        context.lineTo(-15, -15);

        context.restore();
        context.stroke();

        context.font = "10px Monospace";
        context.fillText("dir.x:"+dir.x+" dir.y:"+dir.y, text.x , text.y);
        


        requestAnimationFrame(globalRender);
    }
    document.body.addEventListener("mousemove",function(event){
        mouse.x = event.clientX;
        mouse.y = event.clientY;
        text = centre.getavg(mouse);
    });
    document.body.addEventListener("mousedown",function(event){
        origin.x = event.clientX;
        origin.y = event.clientY;
    });


}

