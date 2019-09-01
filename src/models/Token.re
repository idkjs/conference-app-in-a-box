type t = {
  idToken,
} and idToken = {jwtToken: string};

module Decode = {
  let decodeJwt = json => Json.Decode.{jwtToken: json |> field("jwtToken",string)}
  let decodeToken = json => Json.Decode.{
        idToken: json |> field("idToken", decodeJwt)
  };
  let response = json => decodeToken(json);
  let response = (json: string) : Belt.Result.t(t, string) =>
    try (json |> Json.parseOrRaise |> response |> (u => Belt.Result.Ok(u))) {
    | Json.Decode.DecodeError(decodeError) => Belt.Result.Error(decodeError)
    | e => Belt.Result.Error(e |> Js.String.make)
    };
};

let test = res => Decode.response(res) |> Js.log;
// let test = res => Decode.response(Js.Json.stringify(res)) |> Js.log;