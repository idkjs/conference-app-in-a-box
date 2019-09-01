/**
  This has type:
    array({. "date": option(string), "github": option(string), "id":
            string, "location": option(string), "name": string,
            "speakerAvatar": option(string), "speakerBio": string,
            "speakerName": string, "summary": string, "time": option(string),
            "timeStamp": option(string), "twitter": option(string)})
 */
type t = {
  .
  "id": string,
  "name": string,
  "speakerName": string,
  "speakerBio": string,
  "speakerAvatar": option(string),
  "time": option(string),
  "location": option(string),
  "summary": string,
  "timeStamp": option(string),
  "date": option(string),
  "twitter": option(string),
  "github": option(string),
};
type talks = array(t);
type tTalk = {
  id: string,
  name: string,
  speakerName: string,
  speakerBio: string,
  speakerAvatar: option(string),
  time: option(string),
  location: option(string),
  summary: string,
  timeStamp: option(string),
  date: option(string),
  twitter: option(string),
  github: option(string),
};

let decode = (json: Js.Json.t): tTalk =>
  Json.Decode.{
    id: json |> field("id", string),
    name: json |> field("name", string),
    summary: json |> field("summary", string),
    speakerName: json |> field("speakerName", string),
    speakerBio: json |> field("speakerBio", string),
    speakerAvatar: json |> optional(field("speakerAvatar", string)),
    twitter: json |> optional(field("twitter", string)),
    github: json |> optional(field("github", string)),
    date: json |> optional(field("date", string)),
    timeStamp: json |> optional(field("timeStamp", string)),
    time: json |> optional(field("time", string)),
    location: json |> optional(field("location", string)),
  };
let decodeTalk = (json): tTalk => decode(json);

let talkJson = item =>
  item->Js.Json.stringifyAny->Belt.Option.getExn->Js.Json.parseExn->decodeTalk;
