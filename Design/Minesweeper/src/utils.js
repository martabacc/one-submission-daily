const getRandomNumber = (max) => parseInt(Math.random() * (max));

export const generateCoordinate = (count, max) => {
  const randomCoordinates = [];
  for (let x = 0; x < count; x++) {
    const randomCoordinate = {
      x: getRandomNumber(max),
      y: getRandomNumber(max)
    };
    randomCoordinates.push(randomCoordinate);
  }
  return randomCoordinates;
};

export const getAdjacentCoordinates = ({ x, y, size }) => {
  const coordinates = [];
  const xmin = x - 1 >= 0;
  const ymin = y - 1 >= 0;
  const xinc = x + 1 < Number(size);
  const yinc = y + 1 < Number(size);
  if (xmin) {
    coordinates.push({ x: x - 1, y });
    if (ymin) coordinates.push({ x: x - 1, y: y - 1 });
  }
  if (xinc) {
    coordinates.push({ x: x + 1, y });
    if (yinc) coordinates.push({ x: x + 1, y: y + 1 });
  }

  if (ymin) {
    coordinates.push({ x, y: y - 1 });
    if (xinc) coordinates.push({ x: x + 1, y: y - 1 });
  }
  if (yinc) {
    coordinates.push({ x, y: y + 1 });
    if (xmin) coordinates.push({ x: x - 1, y: y + 1 });
  }

  return coordinates;
};

export const openUntilNumber = (dots) => {
  let leftOverDot = [];
  for (const dot of dots) {
    if (dot.isNumber()) dot.open();
    else if (dot.isEmpty()) leftOverDot.push(...dot.getAdjacent());
  }

  return leftOverDot;
};
