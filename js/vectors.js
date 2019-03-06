window.onload = function(){
    var canvas = document.getElementById("canvas"),
        context = canvas.getContext("2d"),
        width = canvas.width = window.innerWidth,
        height = canvas.height = window.innerHeight,
        centre, mouse, origin, dir;

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
    }
    
    init();
    globalRender();
    
    function init() {
        centre = new PVector(width/2, height/2);
        mouse = new PVector(0,0);
        origin = new PVector(50,50);
    }

    function globalRender() {


        dir = mouse.getsub(centre);
        dir.normalize();
        dir.mult(50);

        
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

        context.beginPath();
        context.lineWidth = 2;
        context.moveTo(50,50);
        context.lineTo(origin.x + dir.x, origin.y + dir.y);
        context.stroke();


        requestAnimationFrame(globalRender);
    }
    document.body.addEventListener("mousemove",function(event){
        mouse.x = event.clientX;
        mouse.y = event.clientY;
    });

}

