function changestate(){
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("txtHint").innerHTML = this.responseText;
      }
    };
    xmlhttp.open("GET", "change" + str, true);
    xmlhttp.send();
}
function getstate(){

}

function change(){
changestate();
if(state==0){state=1;}else{state=0;}
var bo=document.querySelector("body");
var p=document.querySelector("p");
if(state==1){
    p.innerHTML="on";
    p.style.color="#121212";
    bo.style.backgroundColor="#ffffff";
}
else{
    p.innerHTML="off";
    p.style.color="#ffffff";
    bo.style.backgroundColor="#121212";
}

return bo;

}