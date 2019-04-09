package main
import (
  "fmt"
  "net/http"
)

// PlayerServer currently Hello, world for _any_ request
func PlayerServer(w http.ResponseWriter, r *http.Request){
  fmt.Fprint(w, "20")
}
