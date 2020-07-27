type album = {
  title: string,
  count: int,
};

[@bs.module "@react-native-community/cameraroll"]
external deletePhotos: array(string) => Js.Promise.t(unit) = "deletePhotos";

type getAlbumsParams;

[@bs.obj]
external getAlbumsParams:
  (~assetType: [@bs.string] [ | `All | `Photos | `Videos]) => getAlbumsParams;

// multiple externals
[@bs.module "@react-native-community/cameraroll"]
external getAlbums: unit => Js.Promise.t(array(album)) = "getAlbums";

// multiple externals
[@bs.module "@react-native-community/cameraroll"]
external getAlbumsWithParams: getAlbumsParams => Js.Promise.t(array(album)) =
  "getAlbums";

type getPhotosParams;

[@bs.obj]
external getPhotosParams:
  (
    ~first: int,
    ~after: string=?,
    ~groupTypes: [@bs.string] [
                   | `Album
                   | `All
                   | `Event
                   | `Faces
                   | `Library
                   | `PhotoStream
                   | `SavedPhotos
                 ]
                   =?,
    ~groupName: string=?,
    ~assetType: [@bs.string] [ | `All | `Videos | `Photos]=?,
    ~mimeTypes: array(string)=?,
    ~fromTime: float=?,
    ~toTime: float=?,
    ~include_: array(string)=?,
    unit
  ) =>
  getPhotosParams;

type photoIdentifier = {node}
and node = {
  [@bs.as "type"]
  _type: string,
  [@bs.as "group_name"]
  groupName: string,
  image,
  timestamp: float,
  location: Js.Nullable.t(location),
}
and image = {
  filename: Js.Nullable.t(string),
  uri: string,
  height: Js.Nullable.t(float),
  width: Js.Nullable.t(float),
  fileSize: Js.Nullable.t(float),
  playableDuration: Js.Nullable.t(float),
}
and location = {
  latitude: Js.Nullable.t(float),
  longitude: Js.Nullable.t(float),
  altitude: Js.Nullable.t(float),
  heading: Js.Nullable.t(float),
  speed: Js.Nullable.t(float),
};

type photoIdentifiersPage = {
  edges: array(photoIdentifier),
  [@bs.as "page_info"]
  pageInfo,
}
and pageInfo = {
  [@bs.as "has_next_page"]
  hasNextPage: bool,
  [@bs.as "start_cursor"]
  startCursor: Js.Nullable.t(string),
  [@bs.as "end_curson"]
  endCursor: Js.Nullable.t(string),
};

type saveOptions;

[@bs.obj]
external saveOptions:
  (~_type: [@bs.string] [ | `auto | `photo | `video], ~album: string) =>
  saveOptions;

// multiple externals
[@bs.module "@react-native-community/cameraroll"]
external save: string => Js.Promise.t(string) = "save";

// multiple externals
[@bs.module "@react-native-community/cameraroll"]
external saveWithOptions: (string, saveOptions) => Js.Promise.t(string) =
  "save";

// multiple externals
[@bs.module "@react-native-community/cameraroll"]
external saveToCameraRoll: string => Js.Promise.t(string) =
  "saveToCameraRoll";

// multiple externals
[@bs.module "@react-native-community/cameraroll"]
external saveToCameraRollWithType:
  (string, ~_type: [@bs.string] [ | `photo | `video]) => Js.Promise.t(string) =
  "saveToCameraRoll";

[@bs.module "@react-native-community/cameraroll"]
external getPhotos: getPhotosParams => Js.Promise.t(photoIdentifiersPage) =
  "getPhotos";
